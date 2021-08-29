import torch
import torchvision.datasets
from torch import nn
from torch.nn import ReLU
from torch.utils.data import DataLoader

input = torch.tensor([[1, -0.5],
                      [-1, 3]])

input = torch.reshape(input, (-1, 1, 2, 2))
print(input.shape)


class TestNet(nn.Module):
    def __init__(self):
        super(TestNet, self).__init__()
        self.relu1 = ReLU()

    def forward(self, input):
        output = self.relu1(input)
        return output

net = TestNet()
print(net)

output = net(input)
print(output)
