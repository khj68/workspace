import numpy as np




"""
  =========================================
|| COPY Codes from the previous assignment ||
  =========================================
"""

class SGD:
    def __init__(self, gamma, epsilon):
        self.gamma = gamma
        self.epsilon = epsilon

    def update(self, w, grad, lr):
        updated_weight = None
        updated_weight = w - np.multiply(lr, grad)
        return updated_weight

class Momentum:
    def __init__(self, gamma, epsilon):
        self.gamma = gamma
        self.epsilon = epsilon
        self.v = np.zeros((1,1))

    def update(self, w, grad, lr):
        updated_weight = None
        if self.v.size == 1 :
            self.v = np.zeros((w.size//w[0].size, w[0].size))
        self.v = np.multiply(self.gamma, self.v) + np.multiply(lr, grad)
        updated_weight = w - self.v
        return updated_weight

class RMSProp:
    def __init__(self, gamma, epsilon):
        self.gamma = gamma
        self.epsilon = epsilon
        self.Eg = 0

    def update(self, w, grad, lr):
        updated_weight = None

        self.Eg = self.gamma * self.Eg + (1-self.gamma) * (np.multiply(grad,grad))
        updated_weight = w - np.multiply( (lr/((self.Eg+self.epsilon)**0.5)), grad)

        return updated_weight