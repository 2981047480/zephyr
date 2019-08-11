import matplotlib
import matplotlib.pyplot as plt
import numpy as np

dict_data = {}
list_x = []
list_y = []
with open("data_number.txt", "r")as f:
    data = f.read()
    list1 = data.split("\n")
    for i in range(1, len(list1)-1):
        list2 = list1[i].split(" ")
        list_x.append(int(list2[4]))
        list_y.append(int(list2[7]))
        print(len(list2))
print(list_x)
print(list_y)

for i in range(len(list_x)):
    for j in range(len(list_x)-i-1):

        if list_x[j] > list_x[j+1]:
            list_x[j], list_x[j+1] = list_x[j+1], list_x[j]
            list_y[j], list_y[j+1] = list_y[j+1], list_y[j]
print(list_x)
print(list_y)
fig = plt.figure()
ax1 = fig.add_subplot(111)
ax1.set_title('Picture2')
plt.xlabel('area')
plt.ylabel('money')
ax1.scatter(list_x, list_y, c="g", marker='o')
plt.legend('BJ')
plt.show()
