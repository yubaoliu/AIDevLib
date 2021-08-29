import torch
import torchvision
from torch import nn
from torch.nn import MaxPool2d, Conv2d
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter


class TestNet(nn.Module):
    def __init__(self):
        super(TestNet, self).__init__()
        self.conv1 = Conv2d(in_channels=3, out_channels=6, kernel_size=3, stride=1, padding=0)

    def forward(self, input):
        output = self.conv1(input)
        return output


if __name__ == "__main__":
    net = TestNet()
    print(net)

    # TEST using image
    dataset = torchvision.datasets.CIFAR10("../dataset", train=False, download=True, transform=torchvision.transforms.ToTensor())
    dataloader = DataLoader(dataset, batch_size=64)

    writer = SummaryWriter("../logs/conv2d")
    step = 0
    for data in dataloader:
        imgs, targets = data
        output = net(imgs)

        print("[INFO] imgs.shape: {}".format(imgs.shape))
        print("[INFO] output.shape: {}".format(output.shape))
        writer.add_images("input", imgs, step)
        output = torch.reshape(output, (-1, 3, 30, 30))
        writer.add_images("output", output, step)
        step += 1

    writer.close()
