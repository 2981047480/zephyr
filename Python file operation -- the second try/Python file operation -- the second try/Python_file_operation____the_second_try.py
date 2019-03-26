fp=open("C:\\Users\\dell\\Desktop\\样本02.txt","r+")#open the file in mode 'r+'
a=fp.read()#read the file
fp.close()
print(a)#print the file massage
fp=open("C:\\Users\\dell\\Desktop\\样本02.txt","w+")
fp.write(a.replace(" ",","))#replace the ' ' in file with ','
fp.close()#close the file
#The first require has been done