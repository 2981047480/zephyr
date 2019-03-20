def compare(a,b):
    if(a>b):
        print('第一个数大\n')
        return 
    if(a<b):
        print('第二个数大\n')
        return
    else:
        print('两个数相等\n')
        return
i=int(input('请输入第一个数\n'))
k=int(input('请输入第二个数\n'))
compare(i,k)
