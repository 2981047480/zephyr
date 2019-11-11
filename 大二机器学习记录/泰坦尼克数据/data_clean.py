import pandas as pd
import numpy as np

set1=set()
text=pd.read_csv('train.csv',sep=',')
text=np.array(text)
text=text.tolist()
count=0
for j in range(0,len(text)-1):
    if(text[j][5] not in set1):
        set1.add(text[j][5])
        count+=1
#print(set1)
print(count)
list(set1)
set1=set(set1)
print(set1)
# with open('数据统计.txt','a') as fp:
#     fp.writelines(str(set1))
#     fp.write(str(count)+'\n')
