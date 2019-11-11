import numpy as np
import pandas as pd

import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeRegressor
from sklearn.metrics import  mean_absolute_error as mae

data=pd.read_csv('cleaned_data.csv')
data=data.set_index(['Unnamed: 0'])

print(data.shape)

pie_plt=data.groupby(['brand']).sum()['comments'].sort_values(ascending=False)

print(pie_plt)

fig,axes=plt.subplots(figsize=(12,12))
comment_sum=pie_plt.values.sum()
percen=[np.round(each/comment_sum*100,2) for each in pie_plt.values]
axes.pie(pie_plt.values,labels=pie_plt.index,labeldistance=1.2,autopct='%3.1f%%')
axes.legend([pie_plt.index[i]+': '+str(percen[i])+'%' for i in range(len(percen))],loc='upper right',bbox_to_anchor=(1,0,1,1))
axes.set_title('Estimated Handphone Market Share in China')
plt.show()

print(data[(data['brand']=='NOKIA')|(data['brand']=='Philips')]['price'].median())#诺基亚和飞利浦手机价格中位数
print(data[(data['brand']=='NOKIA')|(data['brand']=='Philips')]['price'].mean())#诺基亚和飞利浦手机价格平均数

correlation=data[(data['brand']!='Apple')&(data['price']!=9999)].corr()

fig,axes=plt.subplots(figsize=(8,8))
cax=sns.heatmap(correlation,vmin=-0.25,vmax=1,square=True,annot=True)
axes.set_xticklabels(['RAM','ROM','battery','comments','price','rear camera','resolution','screen size','weight'])
axes.set_yticklabels(['RAM','ROM','battery','comments','price','rear camera','resolution','screen size','weight'])
axes.set_title('Heatmap of Correlation Matrix of numerical data')
plt.show()

print(data.groupby(['brand']).median()['price'].sort_values(ascending=False).values.std())

bar_plt=data.groupby(['brand']).median()['price']

fig,axes=plt.subplots(figsize=(20,8))
axes.bar(bar_plt.index,bar_plt.values)
axes.set_title('Median price of handphones of various brands')
plt.show()

print(data.groupby(['screen material']).median()['price'].sort_values(ascending=False).values.std())#计算不同屏幕材料中位数集合的标准差
print(data.groupby(['screen material']).median()['price'].sort_values(ascending=False))#打印价格和数据类型

bar_plt2=data.groupby(['screen material']).median()['price']

fig,axes=plt.subplots(figsize=(18,8))
axes.bar(bar_plt2.index,bar_plt2.values)
axes.set_title('Median price of handphones of various screen materials')
plt.show()

print(data[(data['brand']=='NOKIA')|(data['brand']=='Philips')]['screen material'].value_counts())

hist_plot=data[(data['screen material']=='IPS')|(data['screen material']=='TFT')]['price']
sns.distplot(hist_plot)
plt.title('Price Distribution Plot of Handphones Whose Screen Material is TFT or IPS ')
plt.show()

print(data.dropna(subset=['ROM','RAM','brand','price']).shape[0]/data.shape[0])

print(data.isnull().sum().sort_values(ascending=False))#所有列缺失值数据统计

df=data.loc[:,['price','rear camera','brand','weight']].dropna()
to_model=pd.get_dummies(df)
x=to_model.iloc[:,1:].values
y=to_model.iloc[:,0].values
model=DecisionTreeRegressor()
model.fit(x,y)

error_list=[]
for each in df['brand'].value_counts().index:
    to_fill='brand_{}'.format(each)
    x_data=to_model[to_model[to_fill]==1].iloc[:,1:].values
    y_data=to_model[to_model[to_fill]==1].iloc[:,0].values

    test_result=model.predict(x_data)
    merror=mae(y_data.reshape(len(y_data),1),test_result.flatten())
    error=(np.abs(test_result-y_data)/y_data).mean()
    print(each,end=' : ')
    print(np.round(merror,2),end=', ')
    print(str(np.round(error*100,3))+'%')
    error_list.append([each,merror,error])

error_df=pd.DataFrame(error_list,columns=['brand','mean_absolute_error','mean_proportional_error'])

print(error_df)