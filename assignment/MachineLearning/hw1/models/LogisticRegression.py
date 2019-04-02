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
        def grad(W, x, y) : 
            batch_size = y.size
            ny = [[y[i]] for i in range(y.size)]
            # f = self._sigmoid(np.dot(x, W))
            # print(np.dot(x,W))
            # print(W)
            print(x)
            data = np.dot(x,W)
            # print(data)
            print(data)
            h = [[self._sigmoid(a[0])] for a in data]
            # print(ny)
            # print(np.subtract(h, y)) 
            # self._sigmoid((np.dot(x,W)).sum())
            sum = 0
            # ny = [[a - f] for a in ny]
            # print(ny)
            data = np.subtract(h,ny)
            # print(data)
            # print(x)
            for i in range(batch_size) :
                for j in range(W.size) :
                    sum +=  data[i][0] * x[i][j]
            # print(sum)
            return sum
        
        for _ in range(epochs) :
            while i<total_size :
                if total_size - i < batch_size :
                    mini_x = x[i:]
                    mini_y = y[i:]
                else:
                    mini_x = x[i : i+batch_size]
                    mini_y = y[i : i+batch_size]
                final_loss = grad(self.W, mini_x, mini_y)
                self.W = optim.update(self.W, lr, final_loss)
                # print(self.W)
                i += batch_size
            i = 0
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
        # print(sample_size)
        w = np.array([a[0] for a in self.W])
        # print('w : ', w)
        for i in range(sample_size) :
            # print(x[i])
            # print(np.dot(x[i], w))
            if(np.dot(x[i], w) >= threshold) :
                pred.append(1)
            else :
                pred.append(0)
            # pred.append(np.dot(x[i], w))
            # print(np.dot(x,self.W.transpose()))

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