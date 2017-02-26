#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 20 23:11:43 2017

@author: Jacobo
"""

import time
import numpy as np

start = time.time()
a=10**5
o=np.array([0])
for i in range(a):
    o=np.hstack((o,np.array([a])))
end = time.time()
print(end - start)
start=time.time()
oo=np.arange(0,a)
print(time.time()-start)