//
//  main.cpp
//  210718-01
//
//  Created by 박경선 on 2021/07/18.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> board(n+1, vector<int>(m+1, 1));

    for(int i = 0; i < puddles.size(); i++) {
        int y = puddles[i][1];
        int x = puddles[i][0];

        board[y][x] = 0;

        if(x == 1)
            for(int j = y; j <=n; j++)
                board[j][1] = 0;

        if(y == 1)
            for(int j = x; j <= m; j++)
                board[1][j] = 0;
    }


    for(int y = 2; y <= n; y++) {
        for(int x = 2; x <= m; x++) {
            if(board[y][x] == 0)
                continue;

            board[y][x] = (board[y-1][x] + board[y][x-1]) % 1000000007;
        }
    }

    return board[n][m];
}
int main() {
    int answer = solution(4, 3, {{2, 2}});
//    int answer = solution(4, 3, {{2, 2}});
    cout << "answer : " << answer << endl;
    return 0;
}
