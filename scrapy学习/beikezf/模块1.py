with open('处理后数据.txt','r',encoding='utf-8') as fp:
    with open('b.txt','w',encoding='utf-8') as fp2:
        str1=fp.read()
        str1=str1.split('\n')
        #print(len(str1))
        for i in range(len(str1)):
            #str2=str1[i].split(' ')
            #print(len(str2))
            #str1[i]=str1[i].replace('元/月','元/月 ')
            #str1[i]=str1[i].replace('  ',' ')
            #str1[i]=str1[i].replace('  ',' ')
            str2=str1[i].split(' ')
            if(i!=0):
                for j in range(0,len(str2)-1):
                    #if(str2[j]=='暂无数据'):
                    #    str2[j]=str2[j].replace('暂无数据','NULL')
                    if(j==9):
                        str2[j]=str2[j].strip('(')
                        str2[j]=str2[j].strip(')')
                    fp2.write(str2[j]+' ')
                fp2.write('\n')