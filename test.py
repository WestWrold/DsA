import numpy
import torch
import time
from torch.autograd import Variable
# refimg_fea = numpy.arange(2*4*3*3).reshape(2,4,3,3)
# targetimg_fea = numpy.arange(2*4*3*3).reshape(2,4,3,3)
refimg_fea = torch.FloatTensor(4,32,64,128).cuda()
targetimg_fea = torch.FloatTensor(4,32,64,128).cuda()
#cost = numpy.zeros((2,8,8,3,3))
cost = torch.FloatTensor(4,64,48,64,128).zero_().cuda()
start = time.clock()
for j in range(100):
    for i in range(48):
            if i > 0 :
                cost[:, ::2, i, :,i:]   = refimg_fea[:,:,:,i:]
                cost[:, 1::2, i, :,i:] = targetimg_fea[:,:,:,:-i]
            else:                           #  0.01686
                cost[:, ::2, i, :,:]   = refimg_fea 
                cost[:, 1::2, i, :,:]   = targetimg_fea
            # if i > 0 :
            #  cost[:, :refimg_fea.size()[1], i, :,i:]   = refimg_fea[:,:,:,i:]
            #  cost[:, refimg_fea.size()[1]:, i, :,i:] = targetimg_fea[:,:,:,:-i]
            # else:
            #  cost[:, :refimg_fea.size()[1], i, :,:]   = refimg_fea
            #  cost[:, refimg_fea.size()[1]:, i, :,:]   = targetimg_fea
    cost = cost.contiguous()
end = time.clock()
print (end-start)/100
