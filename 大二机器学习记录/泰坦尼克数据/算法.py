import warnings#忽略警告提示
warnings.filterwarnings('ignore')

import numpy as np
import pandas as pd

train=pd.read_csv('train.csv')
test=pd.read_csv('test.csv')
print('训练数据集：',train.shape,'测试数据集',test.shape)

rowNum_train=train.shape[0]
rowNum_test=test.shape[0]
print('训练集行数：',rowNum_train)
print('测试集行数',rowNum_test)

full_df=train.append(test,ignore_index=True)
print('合并后的数据集：',full_df.shape)

print(full_df.head())#打印前几行
print(full_df.describe())#查看数据的统计信息
print(full_df.info())#查看每一列的数据类型，数据总数，以及是否有数据缺失

full_df['Fare']=full_df['Fare'].fillna(full_df['Fare'].mean())
full_df['Age']=full_df['Age'].fillna(full_df['Age'].mean())#把年龄和费用（票价）用均值来替代
print(full_df['Embarked'].mode())#查看Embark这一列的众数
full_df['Embarked']=full_df['Embarked'].fillna(full_df['Embarked'].mode())

print(full_df.info())
sex_mapDict={'male':1,'female':0}
full_df['Sex']=full_df['Sex'].map(sex_mapDict)
print(full_df.head())

embarkedDF=pd.DataFrame()
embarkedDF=pd.get_dummies(full_df['Embarked'],prefix='Embarked')#使用get_dummies进行one-hot编码，列名前缀是Embarked
print(embarkedDF.head())

full=pd.concat([full_df,embarkedDF],axis=1)#因为这里用了登船港口(Embarked)进行了one-hot编码产生了它的虚拟变量，所以这里把它删掉
full.drop('Embarked',axis=1,inplace=True)
print(full.head())
print(full.shape)

name1='Braund, Mr. Owen Harris'
str1=name1.split(',')[1]
str2=str1.split('.')[0]
str3=str2.split()

def getTitle(name):
    str1 = name1.split(',')[1]
    str2 = str1.split('.')[0]
    str3 = str2.strip()
    return str3



titleDF=pd.DataFrame()
titleDF['Title']=full['Name'].map(getTitle)
print(titleDF.head())

# full=pd.concat([full,titleDF],axis=1)
#
# full.drop('Name',axis=1,inplace=True)
# print(full.head)
#
# corrDF=full.corr()
# print(corrDF)
#
# print(corrDF['Survived'].sort_values(ascending=False))
#
# full_X=pd.concat([titleDF],axis=1)
# print(full_X.head())