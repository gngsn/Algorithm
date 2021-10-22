#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'abbreviation' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING a
#  2. STRING b
#

def abbreviation(a, b):
    dp = [[False] * (len(a)+1) for _ in range(0, len(b)+1) ]
    bi = ai = cat = 0

    for bi in range(len(b)):
        for ai in range(len(a)):
            if b[bi] == a[ai]:
                dp[bi][ai] = True
            if a[ai].islower():
                if b[bi] == a[ai].upper():
                    dp[bi][ai] = dp[bi][ai-1] or dp[bi-1][ai-1] 
                elif dp[bi][ai-1]:
                    dp[bi][ai] = dp[bi][ai-1]
        print('dp : ', *dp, sep='\n')

    return "YES" if dp[len(b)-1][len(a)-1] else "NO"

if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    q = int(f.readline().strip())

    for q_itr in range(q):
        a = f.readline().strip()

        b = f.readline().strip()

        # print("\n\n")
        result = abbreviation(a, b)
        print('a :', a, ', b : ', b)
        print("result : ", result)

    f.close()
