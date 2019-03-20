a=input('请输入列表的值，中间用空格隔开\n')
a_list=a.split(" ")
for b in a_list[::-1]:
    print(b)
