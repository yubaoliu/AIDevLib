import torch
import torchvision
from torch import nn
from torch.utils.tensorboard import SummaryWriter


class CIFAR10(nn.Module):
    def __init__(self):
        super(CIFAR10, self).__init__()
        self.model = nn.Sequential(
            nn.Conv2d(3, 32, 5, stride=1, padding=2),
            nn.MaxPool2d(2),
            nn.Conv2d(32, 32, 5, stride=1, padding=2),
            nn.MaxPool2d(2),
            nn.Conv2d(32, 64, 5, stride=1, padding=2),
            nn.MaxPool2d(2),
            nn.Flatten(),
            nn.Linear(64 * 4 * 4, 64),
            nn.Linear(64, 10)
        )

    def forward(self, x):
        x = self.model(x)
        return x


if __name__ == '__main__':
    print("Test model")
    writer = SummaryWriter("../logs/cifar")
    net = CIFAR10()
    input = torch.ones(64, 3, 32, 32)
    output = net(input)
    writer.add_graph(net, input)
    print(output.shape)
    writer.close()