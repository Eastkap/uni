#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug  5 18:43:54 2017

@author: nadirabdou
"""
import pandas as pd 
import numpy as np 
import copy
from collections import Counter 
from sklearn.cluster import KMeans
import pickle
import threading
from filelock import FileLock

def purete(liste,k,list_station):
    list_count=[]
    list_final=[]
    maximum=0
   # station=[]
    for i in range (k):
        list_count.append(Counter(liste[i]))
    for j in range (k):
        list_final.append([])
        for z in range (len(list_station)):
            list_final[j].append(list_count[j][list_station[z]])
        maximum+=np.amax(list_final[j])
        #station.append(list_station[list_final[j].index(maximum[j])])
    maximum/=29073
        
    return maximum

def save(dic,binf,bsup):
    pickle.dump(dic,open( "./purete"+str(binf)+str(bsup)+".p", "wb" ) )

class myThread (threading.Thread):
   def __init__(self, threadID,Y,liste_station):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.Y=Y
      self.liste_station=liste_station
   #what to do
   def run(self):
      #threading ici
      with FileLock(".lock"):# work with the file as it is now locked
           print("Lock acquired on thread"+str(self.threadID))
           with open('kafaire.txt', 'r') as fin:
               data = fin.readlines()
           with open('kafaire.txt', 'w') as fout:
               fout.writelines(data[1:])
      #cluster=[]   
      #print('Doing '+str(k[m])
      k=int(data[0])
      while(k!=0):
          cluster=[]
          kmeans = KMeans(n_clusters=k, random_state=0).fit(self.Y)
          res=(kmeans.labels_)
          for j in range (k):
              cluster.append([])
              nad=0
              for i in range (29072):
                  if (res[i]==j):
                      cluster[j].append(self.liste_station[nad//92]) 
                  nad+=1
          score=purete(cluster,k,self.liste_station)
          print(k," ",score)
          with FileLock(".lock"):
              with open("res.txt", "a") as file:
                  file.write(str(k)+","+str(score)+"\n")
          
          with FileLock(".lock"):# work with the file as it is now locked
              print("Lock acquired on thread"+str(self.threadID))
              with open('kafaire.txt', 'r') as fin:
                  data = fin.readlines()
              try:
                  if(int(data[0])!=0):
                      with open('kafaire.txt', 'w') as fout:
                          fout.writelines(data[1:])
                      k=int(data[0])
              except:
                  return
      
          
    #print(str(k[m])+" done")

#%%
def main():
    #df5 = pd.read_csv('/Users/Jacobo/Documents/uni/L2/2i013/data/aggregated_validations-5_minutes.csv', delimiter=";")
    #list_date=df5['operation_date'].unique().tolist()
    #data_station = pd.read_csv('/Users/Jacobo/Downloads/subway_stations.csv', sep=";")
    #charger la matrice jour station 
    df7=pd.read_csv('/Users/Jacobo/Downloads/j2.csv',delimiter=",")
    
    #list_station = data_station['id'].unique().tolist()
    X=df7.as_matrix()
    Z=X.transpose()
    Y=Z[1:]
    liste_stat=[]
    liste2=[]
    #k=[i for i in range (29072)]
    #pureté=[]
    for j in df7:
        liste_stat.append(j)
    liste_stat=liste_stat[1:]
    for i in range(29072):
        liste2.append(liste_stat[i][0:liste_stat[i].find(' ')])
    #%%
    moh=pd.DataFrame(liste2)
    liste_station=moh[0].unique().tolist()
    
    #on lance le threading
    n=int(input('How many threads to run: '))
    binf=int(input('Binf:'))
    bsup=int(input('Bsup (exclue):'))
    print("On initilise")
    with open("./kafaire.txt","w") as file:
        for i in range(binf,bsup):
            file.write(str(i)+"\n")
    ID=0
    threads=[]
    for i in range(n):
       thread = myThread(ID,Y,liste_station)
       thread.start()
       threads.append(thread)
       ID += 1
    
    for t in threads:
        t.join()
    print("Fini: main")

main()

def kilall():
    with FileLock(".lock"):# work with the file as it is now locked
        print("Lock acquired ")
        with open('kafaire.txt', 'w') as fin:
            fin.write("0")
    
#%%
"""
for i in range (141):
    pureté.append(purete(cluster[i],k[i],liste_station))
"""
