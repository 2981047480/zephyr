a=input('请输入10个数，空格隔开\n')
a_list=[int(x) for x in a.split(" ")]
a_list.sort()
print(a_list)