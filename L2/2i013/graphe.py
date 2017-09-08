import matplotlib.pyplot as pl
import numpy as np
import pickle
from random import randint
import pandas as pd


"""
x = np.linspace(0,10,20)   # 20 points entre 0 et 10
y1 = x*x + 2*x             # la fonction a tracer
y2 = np.sqrt(x)            # la fonction a tracer


pl.figure()               # creation d'une figure
pl.subplot(1,2,1)         # division de la fenetre en une matrice 1x2
pl.plot(x,y1,'g--', label='$y = x^2+2x$')
                          # affichage de la courbe + style + etiquette
pl.legend(loc=0)
pl.subplot(1,2,2)
pl.plot(x,y2, 'r*-', label='$y = \sqrt{x}$')
pl.legend(loc=2)          # affichage de la légende en haut a gauche
pl.show()                 # affichage de la fenetre
"""

df = pd.read_csv('/Users/Jacobo/Documents/uni/L2/2i013/data/toutlisse.csv',sep=",")
#print(len(df))

def moyenne_centroide(centroide,k):
    resultat = [[0]*288 for i in range (k)]
    for i in range(k):
        for j in range(len(centroide[i])):
            resultat[i][j%288]+=centroide[i][j]
    return resultat

def jourmoyen(station):
    resultat = [0]*288
    for i in range(len(station)):
        resultat[i%288]+=station[i]
    return resultat

def moyenne_station(station,k):
    return 1

"""
a=mo


tiroir=pickle.load(open("./data/clus11","rb"))

tiroirfini=moyenne_centroide(tiroir)

a=moyenne_centroide(c,11)
for i in range(len(a)):
    pl.figure(i)
    pl.plot(heure,a[i])
    pl.show()
 """  
    
def plot(k):
    c=pickle.load( open( "./data/centroide"+str(k)+".p", "rb" ) )
    df4 = pd.read_csv('./data/toutlisse.csv',sep=",")
    tiroir=pickle.load(open("./data/clus"+str(k)+".p","rb"))
    #heure=pickle.load(open("./data/heures.p","rb"))
    a=moyenne_centroide(c,k)
    #pour le premier
    for i in range (k):
        pl.figure(i)
        for j in range(2):
            indice=randint(0,len(tiroir[i])-1)
            #print(indice," ",len(tiroir[i]))
            station=jourmoyen(df4[str(tiroir[i][indice])])
            suma=sum(station)
            #print(sum([k/suma for k in station]))
            plotdata=[k/suma for k in station]
            pl.plot([k/12 for k in range(24*12)],plotdata,c='r',alpha=.5)
            #pl.xticks([k for k in range(24)])
            
            
        suma=sum(a[i])
        plotdata=[k/suma for k in a[i]]
        pl.title("Centroide n"+str(i)+" ainsi que deux stations aleatoires du cluster")
        pl.plot([k/12 for k in range(24*12)],plotdata,c='g')
        pl.xticks([k for k in range(24)])
        pl.yticks([])
        pl.xlabel('heure')
        pl.ylabel('frequentation normalisee')
        pl.figure(i).savefig("./data/plotcentroidestation"+str(i)+".pdf")
        #pl.show()
#%%

def signalstationmoyenne(station,fenetre):
    """288 ticks sur un jour"""
    df = pd.read_csv('/Users/Jacobo/Documents/uni/L2/2i013/data/toutlisse.csv',sep=",")
    df=df[str(station)]
    courbe = [0]*288
    for i in range(288*3,288*4):
        courbe[i%288]+=df[i]
    for i in range(len(courbe)):
        if (i<int(fenetre/2)):
            courbe[i]=sum(courbe[:int(fenetre/2)+i])/(int(fenetre/2)+i)
        elif (i>len(courbe)-int(fenetre/2)):
            courbe[i]=sum(courbe[len(courbe)-int(fenetre/2):])/(288-i+int(fenetre/2))
        else:
            courbe[i]=sum(courbe[i-int(fenetre/2):i+int(fenetre/2)])/fenetre
    
    pl.title("Lissage avec filtre passe-haut de fenêtre="+str(fenetre))
    pl.plot([k/12 for k in range(24*12)],courbe)
    pl.xlabel('heure')
    pl.ylabel('frequentation normalisee')
    pl.xticks([k for k in range(24)])
    
    #print(courbe)

signalstationmoyenne(198,4)
            
#%%
def difference_centroides(c1,c2,k):
    c=pickle.load( open( "/Users/Jacobo/Documents/uni/L2/2i013/data/centroide"+str(k)+".p", "rb" ) )
    #heure=pickle.load(open("./data/heures.p","rb"))
    a=moyenne_centroide(c,k)
    suma=sum(a[c1])
    plotdata1=[k/suma for k in a[c1]]
    suma=sum(a[c2])
    plotdata2=[k/suma for k in a[c2]]
    plotdata=[plotdata1[i]-plotdata2[i] for i in range(len(plotdata1))]
    pl.title("Differences entre le centroide n"+str(c1)+" et le centroide n"+str(c2))
    pl.plot([k/12 for k in range(24*12)],plotdata,c='g',label="différences")
    #pl.plot([k/12 for k in range(24*12)],[0]*288,c='black',label="y=0")
    #pl.legend(loc='upper left')
    pl.grid(axis='y')
    pl.xticks([k for k in range(24)])
    pl.yticks([0])
    pl.xlabel('heure')
    pl.ylabel('frequentation normalisee')
    pl.savefig("./data/centroide"+str(c1)+"vscentroide"+str(c2)+".pdf")

difference_centroides(0,8,11)
#%%
def signalstationperiode(numstation,i):
    df = pd.read_csv('/Users/Jacobo/Documents/uni/L2/2i013/data/toutlisse.csv',sep=",")
    signal=df[str(numstation)]
    pl.title("Signal de la station "+str(numstation)+" sur la période des données")
    pl.plot([(k/(24*12)) for k in range(len(signal))],signal)
    pl.xticks([k+1 for k in range(0,93,i)]) #len(signal)/(24*12)=92
    #pl.yticks([])
    pl.xlabel('jour (nº)')
    pl.ylabel('fréquentation (u.a.)')
 
signalstationperiode(496,8)

#%%
def plotpurete(k,purete):
    #df = pd.read_csv('/Users/Jacobo/Documents/uni/L2/2i013/data/toutlisse.csv',sep=",")
    #signal=df[str(numstation)]
    #pl.title("Signal de la station "+str(numstation)+" sur la période des données")
    pl.plot(k,purete)
    #pl.xticks(purete) #len(signal)/(24*12)=92
    #pl.yticks(k)
    pl.ylabel('purete')
    pl.xlabel('k')

res=[0.0151343,0.27919375365459359,0.45781309118426033]
k=[100,500,1000]
plotpurete(k,res)
#%%
"""
Lidee serait de prendre 2 stations de chaqu centroide, ensuite, appliquer une moeynne dessus
puis les plotter sur le meme graphique que le centroide en les ayant normalisees

plt.scatter(x,y)
plt.title("Web traffic over the last month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*24 for w in range(10)], 
  ['week %i'%w for w in range(10)])
plt.autoscale(tight=True)
plt.grid()
plt.show()

result=[i/suma for i in a[0]]
pl.plot([i/12 for i in range(24*12)],result)
pl.xticks([i for i in range(24)])
pl.show()

"""