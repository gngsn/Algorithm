#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'connectedCell' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY matrix as parameter.
#
dx = [0,0,1,-1,1,1,-1,-1]
dy = [1,-1,0,0,1,-1,1,-1]
visit = [[False]*10 for _ in range(10)]
cnt = 0

def dfs(mtr, x, y):
    global dx, dy, visit, cnt
    if (x==len(mtr) or x<0 or y==len(mtr[x]) or y<0): return
    visit[x][y] = True
    cnt += 1
    print('x : ',x, ', y : ', y, ', cnt : ', cnt)
    for i in range(8):
        nx = x+dx[i]
        ny = y+dy[i]
        if (nx<len(mtr) and nx>=0 and 
            ny<len(mtr[nx]) and ny>=0 and 
            mtr[nx][ny]==1 and not visit[nx][ny]):
            dfs(mtr, nx, ny)
            
            
    
def connectedCell(matrix):
    global cnt, visit
    mx = 0
    for x in range(len(matrix)):
        for y in range(len(matrix[x])):
            if matrix[x][y]==1 and not visit[x][y]:
                print('\n\nx : ',x, ', y : ', y)
                dfs(matrix, x, y)
                if cnt > mx: mx = cnt
                cnt = 0
            visit[x][y] = True
    return mx

if __name__ == '__main__':
    f = open('./input.txt', 'r+')

    n = int(f.readline().strip())
    m = int(f.readline().strip())

    matrix = []

    for _ in range(n):
        matrix.append(list(map(int, f.readline().rstrip().split())))

    print('matrix : ', matrix)
    result = connectedCell(matrix)
    print('result')
    print(str(result) + '\n')

    f.close()
