//
//  main.cpp
//  211009-01
//
//  Created by 박경선 on 2021/10/09.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool b[m][n];
    stack<char> s[n];
    int count = 1;
    
    while (count > 0) {
        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                cout << board[y][x] << " ";
            }
            cout << "\n";
        }
        fill(&b[0][0], &b[m-1][n], 0);
        count = 0;
        
        for (int y=0; y<m-1; y++) {
            for (int x=0; x<n-1; x++) {
                if (board[y][x] != '.' &&
                    board[y][x] == board[y][x+1] &&
                    board[y][x] == board[y+1][x] &&
                    board[y][x] == board[y+1][x+1]) {
                    b[y][x] = 1;
                    b[y][x+1] = 1;
                    b[y+1][x] = 1;
                    b[y+1][x+1] = 1;
                }
            }
        }
        cout << "\n\n";
        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                cout << b[y][x] << " ";
            }
            cout << "\n";
        }
        
        for (int x=0; x<n; x++) {
            int y=0;
            while(y < m && b[y][x] != 1) {
                s[x].push(board[y][x]);
                board[y++][x] = '.';
            }
            while(y < m && b[y][x] == 1) {
                count++;
                board[y++][x] = '.';
            }
            while(!s[x].empty()) {
                board[--y][x] = s[x].top();
                s[x].pop();
            }
        }
        cout << "\n\n";
        answer += count;
    }
    for (int y=0; y<m; y++) {
        for (int x=0; x<n; x++) {
            cout << board[y][x] << " ";
        }
        cout << "\n";
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> board = {
        "CCZXZ",
        "CCZXZ",
        "XXZXZ",
        "AAZAA",
        "AAAAA",
        "ZAAXX",
    };
    int result = solution(6, 5, board);
//    int result = solution(2, 3, {"CCC", "CDC"});
    cout << "result : " << result << endl;
    return 0;
}
