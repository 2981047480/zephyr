import re


with open('房源信息.txt','r',encoding='utf-8') as fp:
    contains=fp.read()
    #contains=contains.replace(' ',',')
    #contains=contains.replace('\t',',')
    contains=contains.replace('暂无数据','NULL')
    contains=contains.replace('元/月','元/月 ')
    contains=contains.replace('\t',' ')
    contains=contains.replace('  ',' ')
    contains=contains.replace('  ',' ')
    contains=contains.replace('㎡','')
    #contains=contains.replace('/','')
    #contains=contains.replace(' ',',')
    #contains=contains.replace(',,',',')
    print(contains)
    with open('处理后数据.txt','w',encoding='utf-8') as fp1:
        fp1.write(contains)
