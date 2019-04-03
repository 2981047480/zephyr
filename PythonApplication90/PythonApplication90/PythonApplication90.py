f=open("C:\\Users\\dell\\Desktop\\text1.txt","r+")
f1=open("C:\\Users\\dell\\Desktop\\text2.txt","w+")
st = f.read()
x=st.split('\n')
a_list=[[]*6]*(len(x))
b_list=[[0]*3]*(len(x))
for i in range(len(a_list)):
    a_list[i]=x[i].split(',')
for i in range(len(a_list)-1):
    for j in range(3):
        b_list[i][j]=a_list[i][j+3]
        f1.write(b_list[i][j]+' ')
    f1.write('\n')
f,f1.close()
