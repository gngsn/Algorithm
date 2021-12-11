//
//  main.cpp
//  211212-03
//
//  Created by 박경선 on 2021/12/12.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int visited[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int cnt = 0;

void dfs(vector<string> B, int x, int y) {
    cnt++;
    cout << "x : " << x << ", y : " << y << ", count : " << cnt << ", B : " << B[x][y] << endl;
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= B.size() || ny < 0 || ny >= B[0].size()) continue;
        
        if (!visited[nx][ny] && B[nx][ny] == '#') dfs(B, nx, ny);
    }
}

vector<int> solution(vector<string> &B) {
    vector<int> answer = {0, 0, 0};

    for (int i=0; i<B.size(); i++) {
        for (int j=0; j<B[0].size(); j++) {
            if (!visited[i][j] && B[i][j] == '#') {
                cout << "B[i][j] : " << B[i][j] << endl;
                dfs(B, i, j);
                if (cnt == 1) answer[0]++;
                else if (cnt == 2) answer[1]++;
                else answer[2]++;
                cout << "count : " << cnt << endl;
                cnt = 0;
            }
        }
    }
    cout << "answer : " << endl;
    for (int i=0; i<3; i++) cout << answer[i] << " ";
    cout << endl;
    return answer;
}



int main() {
    vector<int> s = {1, 9, 2, 3, 12, 10};
    int result = solution(s, 15);
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
