//
//  64061.cpp
//  level1
//
//  Created by 박경선 on 2021/02/23.
//

#include <iostream>
#include <vector> // for vectors

using namespace std;

class q64061 {
    q64061() {}
    int solution(vector<vector<int>> board, vector<int> moves) {
        int answer = 0;
        size_t size = board.size();
        vector<int> q = {};
        
        for (int move : moves) {
            for (int i =0; i<size; i++) {
                int select = board[i][move-1];
                if (select == 0) continue;
                if (q.size() > 0 && q.back() == select) {
                    q.pop_back();
                    answer += 2;
                }
                else
                    q.push_back(select);
                board[i][move-1] = 0;
                break;
            }
        }
        return answer;
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(NULL); cout.tie(NULL);
        
        vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
        vector<int> moves = {1,5,3,5,1,2,1,4};
        int answer = solution(board, moves);
        cout << "answer : " << answer << "\n";
        
        return 0;
    }
};
