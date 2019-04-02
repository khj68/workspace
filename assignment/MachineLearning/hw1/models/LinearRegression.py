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
        # print(total_size)
        i = 0
        # print(self.W)
        def grad(W, x, y) : 
            batch_size = y.size
            ny = [[y[i]] for i in range(y.size)]
            # print(x)
            # print(W)
            f = np.dot(x, W)
            # print(ny)
            grad_sum = 0
            data = np.subtract(f,ny)
            # print(data)
            for i in range(batch_size) :
                for j in range(W.size) :
                    grad_sum +=  data[i][0] * (x[i][j]/batch_size)
            # print(grad_sum)
            # print(y)
            loss = (data.sum())/(2*batch_size)
            # print(loss)
            return grad_sum, loss
        loss_sum = 0
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
                # print(self.W)
                i += batch_size
                loss_sum += loss
            i = 0
            loss_sum /= (total_size//batch_size)
            print(loss_sum)
        final_loss = loss_sum

        # def hypothesis(X, theta) :
        #     return np.dot(X, theta)
        
        # def gradient(X, y, theta) :
        #     h = hypothesis(X, theta)
        #     grad = np.dot(X.transpose(), (h-y))
        #     return grad
        
        # def cost(X, y, theta) :
        #     h = hypothesis(X, theta)
        #     J = np.dot((h-y).transpose(), (h-y))
        #     J /= 2
        #     return J[0]

        # def create_mini_batches(X, y, batch_size) :
        #     mini_batches = []
        #     data = np.(X,y)
        #     n_minibatches = data.shape[0]
        #     i = 0

        #     for i in range(n_minibatches+1):
        #         mini_batch = data[i * batch_size : (i+1)*batch_size, :]
        #         X_mini = mini_batch[:, :-1]
        #         Y_mini = mini_batch[:, -1].reshape((-1,1))
        #         mini_batches.append((X_mini, Y_mini))
        #     if data.shape[0] % batch_size != 0 :
        #         mini_batch = data[i*batch_size:data.shape[0]]
        #         X_mini = mini_batch[:, :-1]
        #         Y_mini = mini_batch[:, -1].reshape((-1,1))
        #         mini_batches.append((X_mini, Y_mini))
        #     return mini_batches
        
        # error_list = []
        # for _ in range(epochs) :
        #     mini_batches = create_mini_batches(x,y, batch_size)
        #     for mini_batch in mini_batches:
        #         X_mini, y_mini = mini_batch
        #         self.W = self.W - lr*gradient(X_mini, y_mini, self.W)
        #         error_list.append(cost(X_mini, y_mini, self.W))
        
        # print(W, error_list)




        # ============================================================
        return final_loss

    def eval(self, x):
        pred = None

        # Evaluation Function
        # Given the input 'x', the function should return prediction for 'x'

        # ========================= EDIT HERE ========================
        pred = []
        sample_size = x.size//x[0].size
        # print(sample_size)
        w = np.array([a[0] for a in self.W])
        # print('w : ', w)
        for i in range(sample_size) :
            # print(x[i])
            # print(np.dot(x[i], w))
            pred.append(np.dot(x[i], w))
            # print(np.dot(x,self.W.transpose()))

        pred = np.array(pred)
        # ============================================================
        return pred
