import numpy as np


def gravity(ground, a , y, m):
    distance = y - ground
    force = np.round(((a * m) / distance), 0)
    
    return int(force)