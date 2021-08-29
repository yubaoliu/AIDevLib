
import torch
from torch.nn import L1Loss
from torch import nn

inputs = torch.tensor([1, 2, 3], dtype=torch.float32)
targets = torch.tensor([1, 2, 5], dtype=torch.float32)

print("inputs", inputs)
print("targets: ", targets)

inputs = torch.reshape(inputs, (1, 1, 1, 3))
targets = torch.reshape(targets, (1, 1, 1, 3))

loss = L1Loss()
result = loss(inputs, targets)
print("LOSS-mean ", result)

loss = L1Loss(reduction='sum')
result = loss(inputs, targets)
print("LOSS-sum", result)

loss_mse = nn.MSELoss()
result = loss_mse(inputs, targets)
print("LOSS-MSE", result)

x = torch.tensor([0.1, 0.2, 0.3])
y = torch.tensor([1])
x = torch.reshape(x, (1, 3))
loss_cross = nn.CrossEntropyLoss()
result_cross = loss_cross(x, y)
print("LOSS-cross", result_cross)
