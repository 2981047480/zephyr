#!/usr/bin/env python3

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import statsmodels.api as sm
from statsmodels.formula.api import ols,glm

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