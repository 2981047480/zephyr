dict1={}
i=0
with open('处理后数据.csv','r',encoding='utf-8') as fp:
    contains=fp.readlines()
    for contain in contains:
        contain=contain.split(',')
        #print(contain[1])
        if(contain[7] in dict1):
            pass
        else:
            dict1.setdefault(contain[7],i)
            i=i+1
        #print(contain[1])
    with open('字典数据.txt','a',encoding='utf-8') as fp1:
        fp1.write(str(dict1))
        fp1.write('\n')
            