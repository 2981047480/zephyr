import numpy as np
import matplotlib.pyplot as plt
plt.style.use('ggplot')

set0 = set()
set1 = set()
list_area = []
list_money = []
with open("data_number.txt", "r")as f:
    data = f.read()
    list1 = data.split("\n")
    for i in range(1, len(list1)-1):
        list2 = list1[i].split(" ")
        set0.add(list2[4])
        set1.add(list2[7])
        list_area.append(int(list2[4]))
        list_money.append(int(list2[7]))
    print(len(set0))
    print(len(set1))
MIN = MAX = int(list(set0)[0])
for i in range(0, len(set0)):
    middle = int(list(set0)[i])
    if MIN > middle:
        MIN = middle
    if MAX < middle:
        MAX = middle
x0 = []
print(MAX)
print(MIN)
num = 0
for i in range(MIN, MAX+1):
    k = MIN+num
    x0.insert(num, k)
    num = num+1
print(x0)
print(list_area)
plt.hist(list_area, bins=x0, color="blue", histtype='bar', rwidth=1)
plt.xlabel('area')
plt.ylabel('y')
plt.title('Picture1')
plt.legend(labels=["BJ"])
plt.show()


MIN = MAX = int(list(set1)[0])
for i in range(0, len(set1)):
    middle = int(list(set1)[i])
    if MIN > middle:
        MIN = middle
    if MAX < middle:
        MAX = middle
x1 = []
print(MAX)
print(MIN)
num = 0
print(list_money)
for i in range(MIN, MAX+1):
    k = MIN+num
    x1.insert(num, k)
    num = num+1
print(x1)
plt.hist(list_money, bins=len(set1), color="green", histtype='bar', rwidth=5)
plt.xlabel('money')
plt.ylabel('y')
plt.title('Picture1')
plt.legend(labels=["money"])
plt.show()

