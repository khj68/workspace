import numpy as np

"""
DO NOT EDIT ANY PARTS OTHER THAN "EDIT HERE" !!! 

[Description]
__init__ - Initialize necessary variables for optimizer class
input   : gamma, epsilon
return  : X

update   - Update weight for one minibatch
input   : w - current weight, grad - gradient for w, lr - learning rate
return  : updated weight 
"""

class SGD:
    def __init__(self, gamma, epsilon):
        # ========================= EDIT HERE =========================
        self.gamma = gamma
        self.epsilon = epsilon
        # =============================================================

    def update(self, w, grad, lr):
        updated_weight = None
        # ========================= EDIT HERE =========================
        updated_weight = w - np.multiply(lr, grad)

        # =============================================================
        return updated_weight

class Momentum:
    def __init__(self, gamma, epsilon):
        # ========================= EDIT HERE =========================
        self.gamma = gamma
        self.epsilon = epsilon
        self.v = np.zeros((1,1))
        # =============================================================

    def update(self, w, grad, lr):
        updated_weight = None
        # ========================= EDIT HERE =========================
        if self.v.size == 1 :
            self.v = np.zeros((w.size, 1))

        self.v = np.multiply(self.gamma, self.v) + np.multiply(lr, grad)
        updated_weight = w - self.v

        # =============================================================
        return updated_weight


class RMSProp:
    def __init__(self, gamma, epsilon):
        # ========================= EDIT HERE =========================
        self.gamma = gamma
        self.epsilon = epsilon
        self.Eg = 0
        # =============================================================

    def update(self, w, grad, lr):
        updated_weight = None
        # ========================= EDIT HERE =========================

        self.Eg = 0.9 * self.Eg + 0.1 * (np.multiply(grad,grad))
        updated_weight = w - np.multiply( (lr/((self.Eg+self.epsilon)**0.5)), grad)

        # =============================================================
        return updated_weight