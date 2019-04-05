import numpy as np

class LogisticRegression:
    def __init__(self, num_features):
        self.num_features = num_features
        self.W = np.zeros((self.num_features, 1))

    def train(self, x, y, epochs, batch_size, lr, optim):
        final_loss = None   # loss of final epoch

        # Train should be done for 'epochs' times with minibatch size of 'batch size'
        # The function 'train' should return the loss of final epoch
        # Loss of an epoch is calculated as an average of minibatch losses

        # ========================= EDIT HERE ========================
        total_size = y.size
        i = 0
        def get_loss(y ,h) :
            if y == 0 :
                if h == 1 :
                    return 0
                return -np.log(1-h)
            elif y == 1 :
                return -h
        def grad(W, x, y) : 
            batch_size = y.size
            ny = [[a] for a in y]
            f = np.dot(x,W)
            h = [[self._sigmoid(a[0])] for a in f]
            data = np.subtract(h,ny)
            gradient = []
            loss = 0
            for i in range(batch_size) :
                loss += get_loss(y[i], h[i][0])
            for j in range(W.size) :
                grad_sum = 0
                for i in range(batch_size) :
                    grad_sum += data[i][0] * x[i][j]
                gradient.append([grad_sum/batch_size])
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
            final_loss = loss_sum
            print(final_loss)
        # ============================================================
        return final_loss

    def eval(self, x):
        threshold = 0.5
        pred = None

        # Evaluation Function
        # Given the input 'x', the function should return prediction for 'x'
        # The model predicts the label as 1 if the probability is greater or equal to 'threshold'
        # Otherwise, it predicts as 0

        # ========================= EDIT HERE ========================
        pred = []
        sample_size = x.size//x[0].size
        w = np.array([a[0] for a in self.W])
        data = self._sigmoid(np.dot(x, w))
        for i in range(sample_size) :
            if(data[i] >= threshold) :
                pred.append([1])
            else :
                pred.append([0])
        # for i in range(sample_size) :
        #     if(self._sigmoid(np.dot(x[i], w)) >= threshold) :
        #         pred.append([1])
        #     else :
        #         pred.append([0])

        pred = np.array(pred)
        # ============================================================

        return pred

    def _sigmoid(self, x):
        sigmoid = None

        # Sigmoid Function
        # The function returns the sigmoid of 'x'

        # ========================= EDIT HERE ========================
        sigmoid = 1/(1+np.exp(-x))

        # ============================================================
        return sigmoid