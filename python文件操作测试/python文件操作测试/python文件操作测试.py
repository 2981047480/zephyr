#python文件操作，测试篇
fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","r+")
a=fp.read()
print(a)
#运行结果：a得到的值为文件内的所有值
fp.write("python is easy to get start and use.\n")
fp.close()
#运行结果：成功写入文件
fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","r+")
a=fp.readlines()
print(a)
print(a[0][31])
#运行结果：成功读到列表中
fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","r+")
while 1:
    #
    a=fp.readline()
    print(a)
    #else:
    if a=='':
        break
#测试结果：写入、读取成功