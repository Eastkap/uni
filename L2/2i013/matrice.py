import numpy as np
import pickle as pkl     # obligatoire pour pouvoir l'utiliser
import matplotlib.pyplot as pl
import pylab as plt
# chargement de données
#data = pkl.load(file('ressources/usps_small.pkl','rb')) # attention à donner un file + option lecture (pas juste un nom de fichier)
# sauvegarde d'un dictionnaire
#pkl.dump({"letters":letters, "labels":labs}, file("ressources/lettres.pkl","wb"))


a = 2 # variable contenant la valeur 2
m0 = np.array([[1, 2], [3, 4]])     # matrice
print(m0)
                                     # matrice = vecteur de vecteurs
v1 = np.arange(0, 10, 1)
print(v1) # create a range
                          # arguments: start, stop, step
v1 = np.arange(0, 10)    # with default arg
print(v1)

v2 = np.linspace(0, 10, 15) # avec linspace, le début et la fin SONT inclus
#retourne 15 nombres evenly spaces
print(v2)

m1 = np.ones((10,2))  # matrice de 1, argument = nuplet avec les dimensions
                       # ATTENTION np.ones(10,2) ne marche pas
print(m1)

m2 = np.ones((5,4))   # matrice de 0
print(m2)
m3 = np.eye(4)        # matrice identité carrée, arg = dimension
print(m3)
m4 = np.random.rand(5,6)  # matrice de nombres aléatoires indépendants, args = dimensions
print(m4)
m5 = np.random.randn(5,6) # tirages selon une gaussienne(mu=0,var=1), args = dimensions
print(m5)
m6 = m5.T          # pour la transposée
print(m6)
m5.transpose();    # ou bien

np.transpose(m5);  # ou bien


# une matrice d'entier
matInt   = np.zeros((5,6), int) # matrice 5x6 de 0 (entiers)
matBool  = np.zeros((5,6), bool) # matrice 5x6 de False (booléens)
matBool2 = np.ones((5,6), bool) # matrice 5x6 de True (booléens)


#np.savetxt("random-matrix.txt", m5)
# donne le fichier:
# 1.000000000000000000e+00 2.000000000000000000e+00
# 3.000000000000000000e+00 4.000000000000000000e+00
#np.savetxt("random-matrix.csv", m5, fmt='%.5f', delimiter=',')
# donne le fichier:
# 1.00000,2.00000
# 3.00000,4.00000


##exercice final
exo=np.arange(1,10)
print(exo)
new=np.random.rand(1,9)
exo=np.vstack((exo,new))
exo=exo.T
print(exo)
new=np.zeros((9,1))
exo=np.hstack((exo,new))
print(exo)
exo=np.vstack((np.arange(1,4),exo))
print(exo)

Z=np.array(((1,2,3,4,5),(4,5,6,7,8),(7,8,9,10,11)))
#im = plt.imshow(Z,cmap='hot')
#plt.colorbar(im, orientation='horizontal'
fig1, (ax1, ax2)= pl.subplots(2, sharex = True, sharey = False)
ax1.imshow(Z,interpolation="bicubic",aspect="auto")
ax2.imshow(Z,interpolation="none",aspect="auto")

pl.show()

grid = np.array([[1,8,13,29,17,26,10,4],[16,25,31,5,21,30,19,15]])
print('Here is the array')
print(grid)

fig1, (ax1, ax2)= pl.subplots(2, sharex = True, sharey = False)
ax1.imshow(grid, interpolation ='none', aspect = 'auto')
ax2.imshow(grid, interpolation ='bicubic', aspect = 'auto')
pl.show()

data = np.random.random((30, 1295))

fig, ax = plt.subplots()
ax.imshow(data, extent=[-130,130,0,77])
plt.show()
