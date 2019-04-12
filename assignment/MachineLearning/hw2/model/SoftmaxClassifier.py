import numpy as np

class SoftmaxClassifier:
    def __init__(self, num_features, num_label):
        self.num_features = num_features
        self.num_label = num_label
        self.W = np.zeros((self.num_features, self.num_label))

    def train(self, x, y, epochs, batch_size, lr, optimizer):
        """
        N : # of training data
        D : # of features
        C : # of classes

        [INPUT]
        x : (N, D), input data (first column is bias for all data)
        y : (N, )
        epochs: (int) # of training epoch to execute
        batch_size : (int) # of minibatch size
        lr : (float), learning rate
        optimizer : (Python class) Optimizer

        [OUTPUT]
        final_loss : (float) loss of last training epoch

        [Functionality]
        Given training data, hyper-parameters and optimizer, execute training procedure.
        Training should be done in minibatch (not the whole data at a time)
        Procedure for one epoch is as follow:
        - For each minibatch
            - Compute probability of each class for data
            - Compute softmax loss
            - Compute gradient of weight
            - Update weight using optimizer
        * loss of one epoch = Mean of minibatch losses
        (minibatch losses = [0.5, 1.0, 1.0, 0.5] --> epoch loss = 0.75)

        """
        print('========== TRAINING START ==========')
        final_loss = None   # loss of final epoch
        num_data, num_feat = x.shape
        losses = []
        for epoch in range(1, epochs + 1):
            batch_losses = []   # list for storing minibatch losses

        # ========================= EDIT HERE ========================
            i = 0
            while i<y.size :
                if y.size - i < batch_size :
                    mini_x = x[i:]
                    mini_y = y[i:]
                else:
                    mini_x = x[i : i+batch_size]
                    mini_y = y[i : i+batch_size]
                # gradient, loss = grad(self.W, mini_x, mini_y)
                # self.W = optim.update(self.W, lr, gradient)
                prob = self._softmax(mini_x)
                batch_loss = self.softmax_loss(prob, mini_y)
                grad = self.compute_grad(mini_x, self.W, prob, mini_y)
                self.W = optimizer.update(self.W, grad, lr)
                i += batch_size
                batch_losses.append(batch_loss)
            

        # ============================================================
            epoch_loss = sum(batch_losses) / len(batch_losses)  # epoch loss
            # print loss every 10 epoch
            if epoch % 10 == 0:
                print('Epoch %d : Loss = %.4f' % (epoch, epoch_loss))
            # store losses
            losses.append(epoch_loss)
        final_loss = losses[-1]

        return final_loss

    def eval(self, x):
        """

        [INPUT]
        x : (N, D), input data

        [OUTPUT]
        pred : (N, ), predicted label for N test data

        [Functionality]
        Given N test data, compute probability and make predictions for each data.
        """
        pred = None
        # ========================= EDIT HERE ========================
        pred = []
        # print(x)
        softmax = self._softmax(x)
        for row in softmax :
            max = 0
            maxIndex = None
            for j, col in enumerate(row) :
                if col > max :
                    max = col
                    maxIndex = j
            pred.append(maxIndex)
        pred = np.array(pred)
        print(pred)
        # ============================================================
        return pred

    def softmax_loss(self, prob, label):
        """
        N : # of minibatch data
        C : # of classes

        [INPUT]
        prob : (N, C), probability distribution over classes for N data
        label : (N, ), label for each data

        [OUTPUT]
        softmax_loss : scalar, softmax loss for N input

        [Functionality]
        Given probability and correct label, compute softmax loss for N minibatch data
        """
        softmax_loss = 0.0
        # ========================= EDIT HERE ========================
        for i, row in enumerate(prob) :
            if(row[label[i]] != 0):
                softmax_loss += -np.log(row[label[i]])


        # print(softmax_loss/label.size)
        # ============================================================
        return softmax_loss/label.size

    def compute_grad(self, x, weight, prob, label):
        """
        N : # of minibatch data
        D : # of features
        C : # of classes

        [INPUT]
        x : (N, D), input data
        weight : (D, C), Weight matrix of classifier
        prob : (N, C), probability distribution over classes for N data
        label : (N, ), label for each data. (0 <= c < C for c in label)

        [OUTPUT]
        gradient of weight: (D, C), Gradient of weight to be applied (dL/dW)

        [Functionality]
        Given input (x), weight, probability and label, compute gradient of weight.
        """
        grad_weight = np.zeros_like(weight, dtype=np.float32) # (D, C)
        # ========================= EDIT HERE ========================
        # print(prob)
        # print(np.dot(np.transpose(x), prob))
        # grad_weight = np.dot(np.transpose(x), prob)
        # grad_weight = [[col/label.size for col in row] for row in grad_weight]
        # print(x)
        # print(prob)
        # print(grad_weight)
        grad_weight = np.transpose(grad_weight)
        for i, row in enumerate(prob) :
            for j, col in enumerate(row) :
                if j == label[i] :
                    #correct
                    correct_grad = -x[i] + row[label[i]] * x[i]
                    grad_weight[label[i]] += correct_grad/label.size
                else :
                    #wrong
                    wrong_grad = row[j]*x[i]
                    grad_weight[j] += wrong_grad/label.size
        

        grad_weight = np.transpose(grad_weight)
        # print(grad_weight)
        # ============================================================
        return grad_weight


    def _softmax(self, x):
        """
        [INPUT]
        x : (N, C), score before softmax

        [OUTPUT]
        softmax : (same shape with x), softmax distribution over axis-1

        [Functionality]
        Given an input x, apply softmax function over axis-1 (classes).
        """
        softmax = None
        # ========================= EDIT HERE ========================
        softmax = np.dot(x, self.W)
        # print(dot)
        # softmax = [[1000000 if col > 13 else np.exp(col) for col in row] for row in dot]
        # if x[0].size > 100 :
            # softmax = [[ (col - min(row))/(max(row)-min(row)) if (max(row)-min(row)) != 0 else 0 for col in row ] for row in softmax]
        
        # softmax = [[ (abs(col - np.mean(row))) / max(row) if max(row) != 0 else 0 for col in row ] for row in softmax]
        softmax = [[np.exp(col-max(row)) for col in row] for row in softmax]
        # print(softmax)
        
        softmax = [[col/sum(row) if sum(row) != 0 else 0 for col in row] for row in softmax]
        # print(softmax)


        # ============================================================
        return softmax