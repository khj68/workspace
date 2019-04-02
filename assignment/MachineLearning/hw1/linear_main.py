import numpy as np
from utils import _initialize, optimizer

np.random.seed(428)

# ========================= EDIT HERE =========================
# 1. Choose DATA : Concrete / Graduate
# 2. Adjust Hyperparameters
# 3. Choose Optimizer : SGD / Momentum / RMSProp

# DATA
DATA_NAME = 'Concrete'

# HYPERPARAMETERS
batch_size = 64
num_epochs = 50
learning_rate = 0.001
epsilon = 0.01
gamma = 0.01

# OPTIMIZER
OPTIMIZER = 'SGD'
# =============================================================

assert DATA_NAME in ['Concrete', 'Graduate']
assert OPTIMIZER in ['SGD', 'Momentum', 'RMSProp']

# Load dataset, model and evaluation metric
train_data, test_data, linear_regression, metric = _initialize(DATA_NAME)
train_x, train_y = train_data

num_data, num_features = train_x.shape
print('# of Training data : ', num_data)

# Make model & optimizer
model = linear_regression(num_features)
optim = optimizer(OPTIMIZER, gamma=gamma, epsilon=epsilon)

# Print by jun
print(train_x[0])
print(train_y[0])
# TRAIN
loss = model.train(train_x, train_y, num_epochs, batch_size, learning_rate, optim)
print(model)
print('Training Loss at last epoch: %.2f' % loss)

# EVALUATION
test_x, test_y = test_data
pred = model.eval(test_x)
print(pred)

RMSE = metric(pred, test_y)

print(OPTIMIZER, ' RMSE on Test Data : %.2f' % RMSE)