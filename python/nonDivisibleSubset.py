#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'nonDivisibleSubset' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY s
#

m = 0

def nonDivisibleSubset(k, s):
    dic = {}
    answer = 0
    for n in s:
        d = n % k
        dic[d] = dic[d]+1 if d in dic else 1
    
    print("dic : ", dic)
    if 0 in dic : answer = 1

    for i in range(math.ceil(k/2), k):
        op = k - i
        if op == i and i in dic: 
            answer += 1
            continue

        if i in dic and op in dic:
            answer += max(dic[i], dic[op])
        elif i in dic:
            answer += dic[i]
        elif op in dic:
            answer += dic[op]

    return answer




if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    first_multiple_input = f.readline().rstrip().split()
    n = int(first_multiple_input[0])
    k = int(first_multiple_input[1])
    s = list(map(int, f.readline().rstrip().split()))
    print("s : ", s)
    result = nonDivisibleSubset(k, s)

    print("result : ", result)