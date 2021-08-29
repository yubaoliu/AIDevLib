# PyTorch教程】完整的模型训练套路（一）, https://www.youtube.com/watch?v=nm5wWBQJfG0&list=PLgAyVnrNJ96CqYdjZ8v9YjQvCBcK5PZ-V&index=28
import torch
import torchvision
from torch import nn
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter
import time
from CIFAR10 import *

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")   # cpu, cuda:0
print("[INFO] device: {}".format(device))

train_data = torchvision.datasets.CIFAR10(root="../dataset",  train=True, transform=torchvision.transforms.ToTensor(), download=True)
test_data = torchvision.datasets.CIFAR10(root="../dataset", train=False, transform=torchvision.transforms.ToTensor(), download=True)

train_data_size = len(train_data)
test_data_size = len(test_data)
print("[INFO] size of train data: {}".format(train_data_size))
print("[INFO] size of test data: {}".format(test_data_size))

train_dataloader = DataLoader(train_data, batch_size=64)
test_dataloader = DataLoader(test_data, batch_size=64)

tudui = CIFAR10()
tudui = tudui.to(device)
# if torch.cuda.is_available():
#     tudui = tudui.cuda()

loss_fn = nn.CrossEntropyLoss()
loss_fn = loss_fn.to(device)
# if torch.cuda.is_available():
#     loss_fn = loss_fn.cuda()

learning_rate = 0.01    # 1e-2
optimizer = torch.optim.SGD(tudui.parameters(), lr=learning_rate)

total_train_step = 0
total_test_step = 0

epoch = 1000
writer = SummaryWriter("../logs/train")
start_time = time.time()

for i in range(epoch):
    print("-----------------Step: {}-----------------".format(i))
    tudui.train()
    for data in train_dataloader:
        imgs, targets = data
        imgs = imgs.to(device)
        targets = targets.to(device)
        # if torch.cuda.is_available():
        #     imgs = imgs.cuda()
        #     targets = targets.cuda()
        outputs = tudui(imgs)
        loss = loss_fn(outputs, targets)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        total_train_step += 1
        if total_train_step % 100 == 0:
            end_time = time.time()
            print("[TRAIN] Round: {}, loss: {}".format(total_train_step, loss.item()))
            print("[TIME] {}s".format(end_time - start_time))
            writer.add_scalar("train_loss", loss.item(), total_train_step)

    #----------------TEST-----------------
    tudui.eval()
    total_test_loss = 0
    total_accuracy = 0
    with torch.no_grad():
        for data in test_dataloader:
            imgs, targets = data
            imgs = imgs.to(device)
            targets = targets.to(device)
            # if torch.cuda.is_available():
            #     imgs = imgs.cuda()
            #     targets = targets.cuda()
            outputs = tudui(imgs)
            loss = loss_fn(outputs, targets)
            total_test_loss += loss.item()
            accuracy = (outputs.argmax(1) == targets).sum()
            total_accuracy  += accuracy

    print("[TEST] loss: {}".format(total_test_loss))
    print("[TEST] accuracy: {}".format(total_accuracy/test_data_size))

    writer.add_scalar("test_loss", total_test_loss, total_test_step)
    writer.add_scalar("test_accuracy", total_accuracy/test_data_size, total_test_step)
    total_test_step += 1

    # save checkpoint
    # if i % 1000 == 0:
    torch.save(tudui, "../logs/tudui_{}.pth".format(i))
    # torch.save(tudui.state_dict(), "tudui_{}.pth".format(i))
    print("[INFO] saved model")

writer.close()
