import numpy as np

a=int(input('请输入矩阵的元素\n'))
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
g=int(input())
h=int(input())
i=int(input())
A=np.array([[a,b,c],[d,e,f],[g,h,i]])
print(np.trace(A))