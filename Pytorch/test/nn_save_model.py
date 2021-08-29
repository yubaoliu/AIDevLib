import torch
import torchvision

vgg16 = torchvision.models.vgg16(pretrained=False)
torch.save(vgg16, "../logs/vgg16_method1.pth")

torch.save(vgg16.state_dict(), "../logs/vgg16_method2.pth")