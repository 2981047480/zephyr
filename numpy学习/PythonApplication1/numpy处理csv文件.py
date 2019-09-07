import numpy as np
from scipy.stats import scoreatpercentile

data=np.loadtxt("mdrtb_2012.csv",dtype=float,delimiter=',',usecols=(11,),skiprows=1,unpack=True)

print("max method",data.max())
print("max function",np.max(data))

print("min method",data.min())
print("min function",np.min(data))

print("mean method",data.mean())
print("mean function",np.mean(data))

print("std method",data.std())
print("std function",np.std(data))

print("median",np.median(data))
print("score as percentile 50",scoreatpercentile(data,50))