
with open('Êý×Ö.txt','r') as fp:
    a=fp.read()
    a=a.replace(' ',',')
    with open('number.csv','w') as fp1:
        fp1.write(a)