#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'powerSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER X
#  2. INTEGER N
#

dic = {}

def comb(lst, n):
    ret = []
    if n > len(lst): return ret
    
    print ('lst : ', lst)
    if n == 1:
        for i in lst:
            ret.append([i])
    elif n > 1:
        for i in range(len(lst)-n+1):
            for temp in comb(lst[i+1:],n-1):
                ret.append([lst[i]]+temp)

    return ret

# def comb(arr, sub, r, i, depth):
#     print('arr : ', arr)
#     print('sub : ', sub)
#     print('depth : ', depth)
#     if depth == len(arr):
#         return False
#     if r == 0: #check
        # sum = 0
        # for s in sub:
        #     sum += dic[s]
        # return sum
    
#     sub.append(arr[depth])
#     comb(arr, sub[:], r-1, i+1, depth+1)
#     comb(arr, sub[:], r, i, depth+1)

def powerSum(X, N):
    for i in range(int(X**(1/N))):
        dic[i] = pow(i, N)
    
    for i in range(int(X**(1/N))):
        ret = comb(list(dic.keys()), 3)
    
    print('dic : ', dic)
    # for 

if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    X = int(f.readline().strip())
    N = int(f.readline().strip())

    result = powerSum(X, N)

    print(str(result) + '\n')

    f.close()
