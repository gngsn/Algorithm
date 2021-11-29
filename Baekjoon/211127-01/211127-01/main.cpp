//
//  main.cpp
//  211127-01
//
//  Created by 박경선 on 2021/11/27.
//
//

#include <iostream>
#include <string>
#include <time.h>

#include <queue>
#include <vector>

#define INF 2e9
#define START 1

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    vector<pair<int,int>> adj[N+1];
    priority_queue<pair<int,int>> pq;
    vector<int> dij;
    int answer = 0;
    
    dij.resize(N + 1, INF);
    dij[START] = 0;
    
    for(vector<int> ro : road) {
        adj[ro[0]].push_back({ro[1], ro[2]});
        adj[ro[1]].push_back({ro[0], ro[2]});
    }
    
    pq.push({0, START});
    
    while(!pq.empty()) {
        int dist = -pq.top().first;
        int town = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < adj[town].size(); i++) {
            int next = adj[town][i].first;
            int cost = dist + adj[town][i].second;
            
            if (dij[next] > cost) {
                dij[next] = cost;
                pq.push({-dij[next], next});
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
        if (dij[i] <= K) answer++;
    
    return answer;
}

int main() {
    int result = solution(5, {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}}, 3);
//    int result = solution(6, {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}}, 4);
    
    cout << result << endl;
    return 0;
}
