#%%
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import pandas as pd 
import numpy as np 
import copy
import pickle 

df4 = pd.read_csv('./data/toutlisse.csv',sep=",")
list_station = pickle.load( open( "./data/listestations.p", "rb" ) )
#faire la moyenne dans un cluster 


#%%
def moyenne(cluster,df_centroide,k,df4):
    
    for i in range (k): 
        
        if (len(cluster[i])!=0) :
            
            df_centroide[i]=[0 for i in range (26496)]
            for j in range (len(cluster[i])):
                centroide3=df4[str(cluster[i][j])]
                centroide4=centroide3.as_matrix()
                centroide3=pd.DataFrame(centroide4)# pour régler le probléme des index       
                df_centroide[i]+=centroide3[0]
            df_centroide[i]=df_centroide[i]/len(cluster[i]) 
        
    return df_centroide
     
                    

def kmeans (df4,k,list_station,c2):
#Initialisation 
    
    df_centroide=copy.copy(c2)
    cluster = [[] for i in range (k)] 
    
#Les ittérations du k means 

    for z in range (15):
        for i in range (316):    
            station=df4[str(list_station[i])]
            station2=station.as_matrix()
            station=pd.DataFrame(station2)# pour régler le probléme des index 
            df_diff=pd.DataFrame()
            l=[]
            for j in range (k):       
                df_diff[j]=(station[0]-df_centroide[j]).abs()
                diff=(df_diff[j].sum())/26496 
                l.append(diff)           
                
            df_ext=pd.DataFrame(l) # avoir la difference de la station avec touts les centroides 
            minimum=df_ext.min()  # récupérer la valeur de la distance la plus proche entre  la station et les centroides 
            #centroide2=pd.DataFrame()
            cluster[l.index(list(minimum)[0])].append(list_station[i])  # ajouter la station dans le cluster qu'il faut 
            #df_centroide2=df_centroide
        old_centroide=copy.copy(df_centroide)    
        old_cluster=copy.copy(cluster)
      
        cluster = [[] for i in range (k)] 
        df_centroide = moyenne(old_cluster,df_centroide,k,df4)
     
    return old_cluster,old_centroide
#%%
for i in range(11,12):
    centroide = np.random.rand(26496,i)
    df_centroide=pd.DataFrame(centroide)
    c2=df_centroide/100000000000000000  
    clus,centroide = kmeans(df4,i,list_station,c2) 
    pickle.dump( clus, open( "./data/clus"+str(i)+".p", "wb" ) )
    print(i, " done")