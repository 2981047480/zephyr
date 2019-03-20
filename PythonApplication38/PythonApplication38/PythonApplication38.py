a=input('请输入列表，元素间用空格隔开\n')
a_list=a.split(" ")
i=len(a_list)
for i in range(0,i):
    print(a_list[i],end=",")
