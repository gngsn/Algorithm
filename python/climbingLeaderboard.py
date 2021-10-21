#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

def binarySearch(arr, value, low, high):
    if low > high: return low

    mid = int((low + high) / 2)
    if arr[mid] < value: return binarySearch(arr, value, low, mid-1)
    elif arr[mid] > value: return binarySearch(arr, value, mid+1, high)
    else: return mid


def climbingLeaderboard(ranked, player):
    answer = []
    ranked = sorted(set(ranked), reverse=True)
    for p in player:
        idx = binarySearch(ranked, p, 0, len(ranked)-1)
        print("score : ", p, "rank : ", idx+1)
        
        answer.append(idx+1)
    return answer


if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    ranked_count = int(fptr.readline().strip())

    ranked = list(map(int, fptr.readline().rstrip().split()))

    player_count = int(fptr.readline().strip())

    player = list(map(int, fptr.readline().rstrip().split()))

    result = climbingLeaderboard(ranked, player)
    print("result : ", result)
    # fptr.write('\n'.join(map(str, result)))
    # fptr.write('\n')

    fptr.close()
