import re


with open('处理后数据.txt','r',encoding='utf-8') as fp:
    a=fp.read()
    #a=a.replace(' ',',')
    a=a.replace('NULL','0')
    a=a.replace('整租','1')
    a=a.replace('合租','2')
    a=a.replace('(季付价)','1')
    a=a.replace('(年付价)','2')
    a=a.replace('(月付价)','3')
    a=a.replace('(半年付价)','4')
    a=a.replace('(双月付价)','5')
    a=a.replace('随时入住','2')
    a=a.replace('免费使用','1')
    a=a.replace('租用车位','2')
    a=a.replace('民水','1')
    a=a.replace('商水','2')
    a=a.replace('民电','1')
    a=a.replace('商电','2')
    a=a.replace('无','1')
    a=a.replace('有','2')
    a=a.replace('集中供暖','1')
    a=a.replace('自采暖','2')
    #a=a.replace('')
    with open('编码数据.txt','w',encoding='utf-8') as fp1:
        fp1.write(a)


#with open('编码数据.csv','r',encoding='utf-8') as fp:
#    b=fp.readlines()
#    for bs in b:


