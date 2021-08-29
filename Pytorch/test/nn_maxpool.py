import torch
import torchvision
from torch import nn
from torch.nn import MaxPool2d
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter


class TestNet(nn.Module):
    def __init__(self):
        super(TestNet, self).__init__()
        self.maxpool1 = MaxPool2d(kernel_size=3, ceil_mode=True)

    def forward(self, input):
        output = self.maxpool1(input)
        return output


if __name__ == "__main__":
    net = TestNet()
    print(net)

    # input = torch.tensor([[1, 2, 0, 3, 1],
    #                       [0, 1, 2, 3, 1],
    #                       [1, 2, 1, 0, 0],
    #                       [5, 2, 3, 1, 1],
    #                       [2, 1, 0, 1, 1]], dtype=torch.float32)
    # input = torch.reshape(input, (-1, 1, 5, 5))
    # print(input.shape)
    # output = net(input)
    # print(output)

    # TEST using image
    dataset = torchvision.datasets.CIFAR10("../dataset", train=False, download=True, transform=torchvision.transforms.ToTensor())
    dataloader = DataLoader(dataset, batch_size=64)

    writer = SummaryWriter("../logs/maxpool")
    step = 0
    for data in dataloader:
        imgs, targets = data
        print("[INFO] imgs.shape: {}".format(imgs.shape))
        writer.add_images("input", imgs, step)
        output = net(imgs)
        writer.add_images("output", output, step)
        step += 1

    writer.close()
