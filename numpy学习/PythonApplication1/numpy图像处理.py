import scipy.misc
import matplotlib.pyplot as plt
import numpy as np

ascent=scipy.misc.ascent()
acopy=ascent.copy()
aview=ascent.view()
aview.flat=1
plt.subplot(221)
plt.imshow(ascent)
plt.subplot(222)
plt.imshow(acopy)
plt.subplot(223)
plt.imshow(aview)
plt.subplot(224)
plt.imshow(aview)
plt.show()
ascent=scipy.misc.ascent()
xmax=ascent.shape[0]
ymax=ascent.shape[1]
ascent[range(xmax),range(ymax)]=0
ascent[range(xmax-1,-1,-1),range(ymax)]=0
plt.imshow(ascent)
plt.show()
ascent=scipy.misc.ascent()
xmax=ascent.shape[0]
ymax=ascent.shape[1]

def shuffle_indices(size):
    arr=np.arange(size)
    np.random.shuffle(arr)
    return arr

xindices=shuffle_indices(xmax)
np.testing.assert_equal(len(xindices),xmax)
yindices=shuffle_indices(ymax)
np.testing.assert_equal(len(yindices),ymax)
plt.imshow(ascent[np.ix_(xindices,yindices)])
plt.show()

ascent=scipy.misc.ascent()

def get_indices(size):
    arr=np.arange(size)
    return arr%4==0

ascent1=ascent.copy()
xindices=get_indices(ascent.shape[0])
yindices=get_indices(ascent.shape[1])
ascent1[xindices,yindices]=0
plt.subplot(211)
plt.imshow(ascent1)
ascent2=ascent.copy()
ascent2[(ascent>ascent.max()/4)&(ascent<3*ascent.max()/4)]=0
plt.subplot(212)
plt.imshow(ascent2)
plt.show()