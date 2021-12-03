//
//  main.cpp
//  211202-02
//
//  Created by 박경선 on 2021/12/02.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int node[2];
    int distance;
    
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    
    bool operator <(const Edge &edge) const {
        return this->distance < edge.distance;
    }
    
    void to_string() {
        cout << "node1 : " << this->node[0] << ", node2 : " << this->node[1] << ", distance : " << this->distance << endl;
    }
};

int getRoot(int root[], int n) {
    if (root[n] == n) return n;
    return root[n] = getRoot(root, root[n]);
}

bool isCycle(int root[], int a, int b) {
    a = getRoot(root, a);
    b = getRoot(root, b);
    return a == b;
}

void unionRoot(int root[], int a, int b) {
    a = getRoot(root, a);
    b = getRoot(root, b);
    if (a < b) root[b] = a;
    else root[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int root[n];
    
    vector<Edge> v;
    for (vector<int> c: costs) {
        v.push_back(Edge(c[0], c[1], c[2]));
    }
    
    sort(v.begin(), v.end());
    
//    각 정점의 root를 본인으로 초기화
    for (int i=0; i<n; i++) root[i] = i;
    
//    cout << "root : " << endl;
//    for (Edge e: v) e.to_string();
    
    for (int i=0; i< v.size(); i++) {
        if(!isCycle(root, v[i].node[0], v[i].node[1])) {
            answer += v[i].distance;
            unionRoot(root, v[i].node[0], v[i].node[1]);
        }
    }
    
    return answer;
}


int main() {
    int result = solution(4, {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}});
    cout << "result : " << result << endl;
    return 0;
}
