import torch
import torchvision

model1 = torch.load("../logs/vgg16_method1.pth")
print(model1)

model2 = torch.load("../logs/vgg16_method2.pth")
# print(model2)

vgg16 = torchvision.models.vgg16(pretrained=False)
vgg16.load_state_dict(torch.load("../logs/vgg16_method2.pth"))
print(vgg16)