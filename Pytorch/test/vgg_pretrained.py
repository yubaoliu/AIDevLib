import  torchvision

# train_data = torchvision.datasets.ImageNet("../dataset", split="train", download=False, transform=torchvision.transforms.ToTensor())
from torch import nn

vgg16_false = torchvision.models.vgg16(pretrained=False)

# vgg16_true = torchvision.models.vgg16(pretrained=True)

print(vgg16_false)
# print(vgg16_true)

train_data = torchvision.datasets.CIFAR10('../dataset', train=True, transform=torchvision.transforms.ToTensor())

# vgg16_false.add_module('add_linear', nn.Linear(1000, 10))
# vgg16_false.classifier.add_module('add_linear', nn.Linear(1000, 10))
vgg16_false.classifier[6] = nn.Linear(4096, 10)

print(vgg16_false)