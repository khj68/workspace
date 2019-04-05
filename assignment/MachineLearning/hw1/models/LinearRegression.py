import numpy as np

class LinearRegression:
    def __init__(self, num_features):
        self.num_features = num_features
        self.W = np.zeros((self.num_features, 1))

    def train(self, x, y, epochs, batch_size, lr, optim):
        final_loss = None   # loss of final epoch

        # Training should be done for 'epochs' times with minibatch size of 'batch_size'
        # The function 'train' should return the loss of final epoch
        # Loss of an epoch is calculated as an average of minibatch losses

        # ========================= EDIT HERE ========================
        total_size = y.size
        i = 0
        def grad(W, x, y) : 
            batch_size = y.size
            ny = [[a] for a in y]
            f = np.dot(x, W)
            data = np.subtract(f,ny)
            gradient = []
            for j in range(W.size) :
                grad_sum = 0
                for i in range(batch_size) :
                    grad_sum += data[i][0] * (x[i][j]/batch_size)
                gradient.append([grad_sum])
            data = np.array([[a[0]**2] for a in data])
            loss = (data.sum())/(2*batch_size)
            return gradient, loss

        for _ in range(epochs) :
            loss_sum = 0
            while i<total_size :
                if total_size - i < batch_size :
                    mini_x = x[i:]
                    mini_y = y[i:]
                else:
                    mini_x = x[i : i+batch_size]
                    mini_y = y[i : i+batch_size]
                gradient, loss = grad(self.W, mini_x, mini_y)
                self.W = optim.update(self.W, lr, gradient)
                i += batch_size
                loss_sum += loss
            i = 0
            if(total_size % batch_size != 0) :
                loss_sum /= (total_size//(batch_size+1))
            else :
                loss_sum /= (total_size//(batch_size))
            print(loss_sum)
        final_loss = loss_sum

        # ============================================================
        return final_loss

    def eval(self, x):
        pred = None

        # Evaluation Function
        # Given the input 'x', the function should return prediction for 'x'

        # ========================= EDIT HERE ========================
        pred = []
        sample_size = x.size//x[0].size
        w = np.array([a[0] for a in self.W])
        for i in range(sample_size) :
            pred.append([np.dot(x[i], w)])

        pred = np.array(pred)
        # ============================================================
        return pred
