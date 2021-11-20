#!/bin/python3

import math
import os
import random
import re
import sys
import time

#
# Complete the 'minimumLoss' function below.
#
# The function is expected to return an INTEGER.
# The function accepts LONG_INTEGER_ARRAY price as parameter.
#

def minimumLoss(price):
    sp = sorted(enumerate(price), key=lambda x:x[1])
    # print([sp[i+1][1]-sp[i][1] for i in range(len(sp)-1) if sp[i+1][0]<sp[i][0]])
    # print(list(sp[i+1][1]-sp[i][1] for i in range(len(sp)-1) if sp[i+1][0]<sp[i][0]))
    return min((sp[i+1][1]-sp[i][1] for i in range(len(sp)-1) if sp[i+1][0]<sp[i][0]))
    

if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    n = int(f.readline().strip())
    price = list(map(int, f.readline().rstrip().split()))

    start = time.time()
    result = minimumLoss(price)
    print("time :", time.time() - start) 
    print(str(result) + '\n')

    f.close()
