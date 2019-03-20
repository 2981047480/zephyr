print('第一个列表')
a_list=[[1,2,3],[4,5,6],[7,8,9]]
for i in range(0,3):
    print(a_list[i])
print('第二个列表')
b_list=[[1,2,3],[4,5,6],[7,8,9]]
for i in range(0,3):
    print(b_list[i])
print('第三个列表为两个列表同位置的数相加构成')
c_list=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(0,len(a_list)):
    for j in range(len(a_list[i])):
        c_list[i][j]=a_list[i][j]+b_list[i][j] 
print('输出第三个列表为:')
for i in range(0,3):
    print(c_list[i]) 
for i in range(0,len(a_list)):
    for j in range(len(a_list[i])):
        c_list[i][j]=a_list[i][j]+b_list[i][j]
print('输出第三个列表为:')
for i in range(0,3):
    print(c_list[i])