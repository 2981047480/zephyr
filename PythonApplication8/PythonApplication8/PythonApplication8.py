for i in range(1,9):
    for j in range(1,i+1):
        k=i*j
        if(j==1):
            print('\t')
        print("""%d*%d=%d""" % (i,j,i*j),end='\t')
