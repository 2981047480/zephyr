#!/usr/bin/env python3

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import statsmodels.api as sm
from statsmodels.formula.api import ols,glm


#将数据集读入到pandas数据框中
wine=pd.read_csv('C:\\Users\\DELL\\Desktop\\winequality-both.csv',delimiter="\t",encoding='utf-8',header=None,sep ='\t')
wine.columns=wine.columns.str.replace(' ','_')
print(wine.head())
#显示所有变量的描述性统计量
print(wine.describe())
#找出唯一值
print(sorted(wine.quality.unique()))
#计算值的频率
print(wine.quality.value_counts())

#按照葡萄酒类型显示质量的描述性统计量
print(wine.groupby('type')[['quality']].describe().unstack('type'))
#按照葡萄酒类型显示质量的特定分位数值
print(wine.groupby('type')[['quality']].quantile([0.25,0.75]).unstack('type'))
#按照普塔啤酒类型查看质量分布
red_wine=wine.loc[wine['type']=='red','quality']
white_wine=wine.loc[red_wine['type']=='while',quality]
sns.set_style("dark")
print(sns.distplot(red_wine,norm_hist=True,kde=False,color="red",label="Red wine"))
print(sns.distplot(white_wine,norm_hist=True,kde=False,color="white",label="White wine"))
sns.axlabel("Quality Score","Density")
plt.title("Distribution of Quality by Wine Type")
plt.legend()
plt.show()
#检验红葡萄酒和白葡萄酒的平均质量是否有所不同
print(wine.groupby(['type'])[['quality']].agg(['std']))
tstat,pvalue,df=sm.stats.ttest_ind(red_wine,white_wine)
print('tstat: %.3f pvalue: %.4f' % (tstat,pvalue))