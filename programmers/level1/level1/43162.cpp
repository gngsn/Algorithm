//
//  43162.cpp
//  level1
//
//  Created by 박경선 on 2021/02/25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class p43162 {
    void dfs(int n, vector<vector<int>> computers, int com, vector<bool> &visited) {
        if (visited[com]) return;
        visited[com] = true;
        
        for (int i=0; i<n; i++) {
            if (computers[com][i]) {
                dfs(n, computers, i, visited);
            }
        }
    }
    
    int solution(int n, vector<vector<int>> computers) {
        int answer = 0;
        vector<bool> visited(computers.size(), false);
        
        for (int c = 0; c < n; c++) {
            if (visited[c]) continue;
            answer++;
            dfs(n, computers, c, visited);
        }
        return answer;
    }
    
    int main() {
        int n = 3;
        vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        vector<vector<int>> computers2 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
        
        int answer = solution(n, computers2);
        cout << "answer : " << answer << endl;
        return 0;
    }
};
