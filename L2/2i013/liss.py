import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


df = pd.read_csv('./data/aggregated_validations-5_minutes.csv', delimiter=";")
#df = df[(df.operation_date == '2015-10-01')]

# create dataframe with sum group by station in order to normalize

df_sum = df.groupby(['station_id','operation_date']).sum()


# add column sum and normalize

df_sum.reset_index(inplace=True) # 'inplace=True' -> modify the DataFrame in place
df_sum.rename(columns={'count':'somme'}, inplace=True) # rename the column 'count' into 'somme'
df = df.merge(df_sum, on=['station_id','operation_date'], how='left') # add df_sum to df on the left 
df['count_norm'] = df['count']/df['somme'] # divide i.e. normalize


# convert column operation_datetime & time into pandas type datetime

df['operation_datetime'] = pd.to_datetime(df['operation_date'] +' ' + df['time'])

    
# Create date range with 5min interval step

min_operation_datetime = df['operation_datetime'].min()
max_operation_datetime = df['operation_datetime'].max()
daterange_index = pd.date_range(min_operation_datetime,max_operation_datetime, freq='5min')

# get list of all stations

list_station = df['station_id'].unique().tolist() 

# generate new dataframe with 0 in each line                 
                 
index = pd.MultiIndex.from_product([list_station,daterange_index], names=['station_id','operation_datetime'])

dataframe_range = pd.DataFrame(index=index)
#dataframe_range['dummy'] = 0 (useless)
 
# merge with df 

dataframe_range.reset_index(inplace=True)
df = df.merge(dataframe_range, on=['station_id','operation_datetime'], how='right') # right: use only keys from right frame
df['count_norm']  = df['count_norm'].fillna(0) # fill with 0

df = df[['station_id','operation_datetime','count_norm']] # drop useless columns
df = df.sort(['station_id', 'operation_datetime'])
df.reset_index(drop=True)

df = df.pivot(index='operation_datetime', columns='station_id', values='count_norm')


for column in df:
    df[column] = pd.rolling_mean(df[column], window=10, center=True)
    df[column]  = df[column].fillna(0) 


df.to_csv('./data/unjour.csv', index=False)# header=None

"""mat = np.loadtxt(open("/home/antoine/Projet/Final/TestMax5.csv", "rb"), delimiter=",")
plt.imshow(mat)               
plt.colorbar()  

FutureWarning: sort(columns=....) is deprecated, use sort_values(by=.....)
  df = df.sort(['station_id', 'operation_datetime'])
liss.py:58: FutureWarning: pd.rolling_mean is deprecated for Series and will be removed in a future version, replace with
	Series.rolling(window=10,center=True).mean()
  df[column] = pd.rolling_mean(df[column], window=10, center=True)

"""
