with open('±àÂëÊý¾Ý.csv','r') as fp:
    a=fp.read()
    b=a.split('\n')
    for i in range(1,3001):
        c=b.split(',')
        if(int(c[7])>11000 or int(c[4])>150):
            print(b[i])