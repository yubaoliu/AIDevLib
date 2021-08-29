import torch
import torchvision.datasets
from torch import nn
from torch.nn import ReLU, Sigmoid
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter

input = torch.tensor([[1, -0.5],
                      [-1, 3]])

input = torch.reshape(input, (-1, 1, 2, 2))
print(input.shape)


class TestNet(nn.Module):
    def __init__(self):
        super(TestNet, self).__init__()
        self.relu1 = ReLU()
        self.sigmoid1 = Sigmoid()

    def forward(self, input):
        output = self.sigmoid1(input)
        return output


net = TestNet()
print(net)

dataset = torchvision.datasets.CIFAR10("../dataset", train=False, transform=torchvision.transforms.ToTensor(),
                                       download=True)
dataloader = DataLoader(dataset, batch_size=64)

step = 0
writer = SummaryWriter("../logs/sigmoid")
for data in dataloader:
    imgs, targets = data

    output = net(imgs)
    print(output.shape)
    writer.add_images("input", imgs, step)
    writer.add_images("output", output, step)
    step += 1

writer.close()