import torch
import torchvision.transforms
from PIL import Image
from CIFAR10 import CIFAR10

# 3->cat 5->dog
image_path = "../imgs/cat.jpg"
image = Image.open(image_path)
print(image)
# image.show()

transform = torchvision.transforms.Compose([torchvision.transforms.Resize((32,32)),
                                            torchvision.transforms.ToTensor()])

image = transform(image)
print(image.shape)

model = torch.load("../logs/tudui_2.pth", map_location=torch.device("cpu"))
print(model)

image = torch.reshape(image, (1, 3, 32, 32))

# device = torch.device("cuda" if torch.cuda.is_available() else "cpu")   # cpu, cuda:0
# image = image.to(device)

model.eval()
with torch.no_grad():
    output = model(image)

print(output)
print(output.argmax(1))