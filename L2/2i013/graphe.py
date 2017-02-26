import matplotlib.pyplot as pl
import numpy as np

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
