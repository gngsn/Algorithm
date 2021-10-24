#!/bin/python3

import math
import os
import random
import re
import sys
from itertools import combinations

#
# Complete the 'powerSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER X
#  2. INTEGER N
#

# def powerSum(X, N):
#     dic = []
#     dp = [0] * (X+1)
#     for i in range(1, int(X**(1/N)+1)):
#         dic.append(pow(i, N))

#     dp[0]=1
#     for k in dic:
#         print('k : ', k)
#         for n in range(X-k, -1, -1):
#             if dp[n] > 0 :
#                 dp[n+k] += dp[n]
    
#     print('dp : ', dp)
#     return dp[X]

def comb(array, r):
    print('array : ', array)
    for i in range(len(array)):
        if r == 1:
            yield [array[i]]
        else:
            for next in comb(array[i+1:], r-1):
                yield [array[i]] + next


def powerSum(X, N):
    p = []
    answer = 0
    for i in range(1, int(X**(1/N)+1)):
        p.append(pow(i, N))
    
    
    
    print('comb : ',next(comb(p, 2)))
    dic = {}
    # for i in range(1, len(p)+1):
    #     lst = combinations(p, i)
    #     # print('lst : ', list(lst))

    #     for tpl in lst:
    #         dic[tpl] = sum(tpl)
    #         if sum(tpl) == X : answer += 1

    return answer



if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    X = int(f.readline().strip())
    N = int(f.readline().strip())

    result = powerSum(X, N)

    print(str(result) + '\n')

    f.close()
