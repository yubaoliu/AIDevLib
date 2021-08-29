import torch
import torchvision
from torch import nn
from torch.nn import Linear
from torch.utils.data import DataLoader

dataset = torchvision.datasets.CIFAR10("../dataset", train=False, transform=torchvision.transforms.ToTensor(),
                                       download=True)

dataloader = DataLoader(dataset, batch_size=64, drop_last=True)


class TestNet(nn.Module):
    def __init__(self):
        super(TestNet, self).__init__()
        self.linear1 = Linear(196608, 10)

    def forward(self, input):
        output = self.linear1(input)
        return output


net = TestNet()
print(net)

# for data in dataloader:
#     imgs, targets = data
#     # BCHW
#     print("input: {}".format(imgs.shape))
#
#     output = torch.reshape(imgs, (1, 1, 1, -1))
#     print("output: {}".format(output.shape))

step = 0
for data in dataloader:
    imgs, targets = data
    # BCHW
    print("input: {}".format(imgs.shape))

    output = torch.flatten(imgs)
    print("output: {}".format(output.shape))
    output = net(output)
    print("output: {}".format(output.shape))
