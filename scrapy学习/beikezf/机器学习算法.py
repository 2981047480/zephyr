import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

def load_housing_data():
    return  pd.read_csv('a.csv')


housing=load_housing_data()
print(housing.head())
print(housing.info())
print('\n')
print(housing.describe())#describe()查看数据集的详细信息
# print(housing['city'].value_counts())
# print(housing['position'].value_counts())
# housing.hist(bins=50,figsize=(15,10))#bin:柱子个数
# #plt.savefig('a.jpg')
# plt.show()

#观察price的数据分布
plt.figure(figsize = (10,5))
# plt.xlabel('price')
sns.distplot(housing['money'])
plt.show()


#自变量与因变量的相关性分析
plt.figure(figsize = (20,10))
internal_chars=housing.columns.values.tolist()
corrmat = housing[internal_chars].corr()  # 计算相关系数
sns.heatmap(corrmat, square=False, linewidths=.5, annot=True) #热力图


#先将数据集分成训练集和测试集
x = housing.drop('money',axis=1)
y = housing['money']
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(x, y, test_size=0.2, random_state=21)

#模型建立
from sklearn import metrics
def RF(X_train, X_test, y_train, y_test):    #随机森林
    from sklearn.ensemble import RandomForestRegressor
    model= RandomForestRegressor(n_estimators=200,max_features=None)
    model.fit(X_train, y_train)
    predicted= model.predict(X_test)
    mse = metrics.mean_squared_error(y_test,predicted)
    return (mse/10000)

def LR(X_train, X_test, y_train, y_test):    #线性回归
    from sklearn.linear_model import LinearRegression
    LR = LinearRegression()
    LR.fit(X_train, y_train)
    predicted = LR.predict(X_test)
    mse = metrics.mean_squared_error(y_test,predicted)
    return (mse/10000)

print('RF mse: ',RF(X_train, X_test, y_train, y_test))
print('LR mse: ',LR(X_train, X_test, y_train, y_test))

predicted=RF(X_train, X_test, y_train, y_test)
list1=predicted.tolist()
# for i in range(600):
#     list1.append(predicted[i])
list2=[]
for i in y_test:
    list2.append(i)
list3=[]
for i in range(0,600):
    number1=abs(int(list1[i])-list2[i])/list2[i]
    number=abs(1-number)
    list3.append(number)
sum=0
for n in list3:
    sum+=n
per=sum/600
print(per)



#划分测试集
# def split_train_test(data,test_ratio):
#     indices=np.random.permutation(len(data))#全随机排列
#     test_size=int(len(data)*test_ratio)
#     test_indices=indices[:test_size]
#     train_indices=indices[test_size:]
#     return data.iloc[train_indices],data.iloc[test_indices]
#
# train_set,test_set=split_train_test(housing,0.2)
# print("train set len",len(train_set))
# print("test set len",len(test_set))
# ('train set len',2400)
# ("test set len",600)
#这里原本有一个固定随机选取的函数，这里让他随机，所以略去那段

#sklearn自带的划分数据集的方法
# from sklearn.model_selection import train_test_split
# train_set,test_set=train_test_split(housing,test_size=0.2)
#如果要确定，不每次随机取的话需要加一个参数train_set,test_set=train_test_split(housing,test_size=0.2,random_state=42)

#housing["income_cat"] = np.ceil(housing["money"] / 1.5)
# Label those above 5 as 5
# housing["income_cat"].where(housing["income_cat"] < 5, 5.0, inplace=True)
# housing["income_cat"].hist()

#接下来按照类别划分数据集
# from sklearn.model_selection import StratifiedShuffleSplit
# split=StratifiedShuffleSplit(n_splits=1,test_size=0.2)
# for train_index,test_index in split.split(housing,housing['income_cat']):
#     start_train_set=housing.loc[train_index]
#     start_test_set=housing.loc[test_index]
#     for set_ in (strat_train_set, strat_test_set):
#         set_.drop("income_cat", axis=1, inplace=True)
#可视化数据
# housing=strat_train_set.copy()

