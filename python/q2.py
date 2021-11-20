#!/bin/python3

import math
import os
import random
import re
import sys
import time


if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    n = int(f.readline().strip())
    price = list(map(int, f.readline().rstrip().split()))

    start = time.time()
    result = minimumLoss(price)
    print("time :", time.time() - start) 
    print(str(result) + '\n')

    f.close()
