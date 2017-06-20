# -*- coding: utf-8 -*-
"""
Éditeur de Spyder

Ceci est un script temporaire.
"""

from numpy import *
from math import pi
import matplotlib.pyplot as plt

##exercice 1
u=array([[1],[-1],[2]])
v=array([[10],[-1],[3]])
w=array([[5],[-1],[4]])

print(3*u)
print(linalg.norm(u,2))
print(2*u-v+5*w)
print(linalg.norm(2*u-v+5*w,1))
print(linalg.norm(w-4*v,inf))
print(vdot(u,v))

##Exercice 2

u1=array([[1],[-3],[3],[5],[4]])
u2=array([[0],[1],[2],[4],[3]])
u3=array([[2],[-5],[-1],[-6],[1]])
u4=array([[3],[4],[5],[-2],[0]])

A=hstack((u1,u2,u3,u4))
print(linalg.matrix_rank(A))
A[:,3]=[ -3,11,4,13 ,4]
print(linalg.matrix_rank(A))

##Exercice 3
A=matrix([[1,3,2],[-5,3,1],[-10,0,3],[1,0,-2]])
B=matrix([[1,-2,5],[6,1,-1]])
C=matrix([[10,-5],[3,1]])

print(A.shape)
print(B.size)

print(dot(A,B.T))
print(eye(2)-dot(B,(B.T)))
D=dot(A,(A.T))

vp, vecp = linalg.eig(D)
print("aa",max(abs(vp)))
print(vecp)

print("tout devrait faire 0:")
#malheuresement a cause des flotans on a e-16 au lieu de 0
for i in range(D.shape[0]):
    print(dot((D-dot(vp[i],eye(D.shape[0]))),vecp[:,i]))
    
##Exercice 4
A=matrix([[1,-1,7],[-4,2,11],[8,0,3]])
B=matrix([[3,-2,-1],[7,8,6],[5,1,3]])
print(A*pi)
print(A*B)
print(dot(A,ones(A.shape)))
d=diag(A)
B=B-dot(eye(3),diag(B))
C=hstack((A,B))
D=vstack((A,B))

#je ne vois pas comment eviter la boucle pour la 4:7

print("elements",B[0:B.shape[0]+1:2,0:B.shape[1]+1:2])
print(B)

print(D)
print("elements",D[0:D.shape[0]+1:2,0:D.shape[1]+1:2])


#Exercice 5
def vectalea(n):
    v=random.rand(n)
    #diviser par sa norme 2
    v=v/linalg.norm(v,2)
    return v
    
def fonctiondeux(n):
    return random.randint(2, size=(n, n))


#Exercice 6
def fonctionsomme(n):
    res=0
    for i in range(n+1):
        temp=1/(2*i+1)
        if i%2==1:
            temp=-temp
        res=res+temp
    return res

def precision(epsilon):
    i=0
    while(abs(pi-4*fonctionsomme(i))<epsilon):
        i=i+1
    return i
    
y= [abs(pi-4*fonctionsomme(i)) for i in range(3,101)]
x= range(3,101)

plt.plot(x,y)
plt.show()