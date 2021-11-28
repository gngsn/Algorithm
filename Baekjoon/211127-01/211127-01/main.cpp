//
//  main.cpp
//  211127-01
//
//  Created by 박경선 on 2021/11/27.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <time.h>
#define MAX_TIME 500001
#define MAX_TOWN 51

using namespace std;

template <typename T>
void printvector(vector<T> arr) {
    cout << "arr : ";
    for (T a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;
    int start = 1;
    int adj[MAX_TOWN][MAX_TOWN];
    priority_queue<pair<int,int>> q;
    adj[1][1] = 0;
    for (int k = 1; k <= N; k++)
        for (int j = 1; j <= N; j++)
            adj[k][j] = MAX_TIME;
    
    for(vector<int> ro : road) {
        if (adj[ro[0]][ro[1]] < ro[2])
            continue;
        adj[ro[0]][ro[1]] = ro[2];
        adj[ro[1]][ro[0]] = ro[2];
    }
    
    q.push({1, 1});
    while(!q.empty()) {
        int dist = -q.top().first;
        int town = q.top().second;
        cout << "dist : " << dist << ", town : " << town << endl;
        q.pop();
        
        for(int i = start+1; i <= N; i++) {
            if (town == i) continue;
            if (adj[start][i] > adj[start][town] + adj[town][i]) {
                adj[start][i] = adj[start][town] + adj[town][i];
                adj[i][start] = adj[start][town];
                q.push({-adj[start][i], i});
            }
        }
    }
    for (int k = start+1; k <= N; k++)
        if (adj[start][k] <= k) answer++;

    cout << "adj : " << endl;
    for (int k = 1; k <= N; k++) {
        for (int j = 1; j <= N; j++) {
            cout << adj[k][j] << " ";
        }
        cout << endl;
    }
    
    return answer;
}

int main() {
    int result = solution(5, {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}}, 3);
//    int result = solution(6, {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}}, 4);
    
    cout << result << endl;
    return 0;
}
