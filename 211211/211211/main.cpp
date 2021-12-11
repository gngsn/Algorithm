//
//  main.cpp
//  211211
//
//  Created by 박경선 on 2021/12/11.
//

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct Edge {
    int node[2];
    float distance;
    
    Edge(int a, int b, float distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    
    bool operator <(const Edge &edge) const {
        return this->distance < edge.distance;
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

void to_string(Edge e) {
    cout << "a : " << e.node[0] << ", b : " << e.node[1] << ", dist : " << e.distance << endl;
}


int solution(vector<int> x, vector<int> y) {
    int answer = 0;
    int root[x.size()];
    
    vector<Edge> v;

    for (int i=0; i<x.size(); i++) {
        for (int j=i+1; j<x.size(); j++) {
            // cout << "i : " << i << ", j : " << j << ", sub : " << abs(x[i]-x[j]) << " , " << abs(y[i]-y[j]) << ", sqrt : "<< sqrt(pow(abs(x[i]-x[j]), 2) + pow(abs(y[i]-y[j]), 2)) << endl;
            float dist = sqrt(pow(abs(x[i]-x[j]), 2) + pow(abs(y[i]-y[j]), 2));
            v.push_back(Edge(i, j, dist));
        }
    }
    
    sort(v.begin(), v.end());
    
    for (int i=0; i<x.size(); i++) {
        root[i] = i;
//        to_string(v[i]);
    }
    
    for (int i=0; i< v.size(); i++) {
//        for (int j=0; j< v.size(); j++) cout << root[i] << " ";
        if(!isCycle(root, v[i].node[0], v[i].node[1])) {
            cout << "dist : " << v[i].distance << endl;
            if (v[i].distance > answer) answer = ceil(v[i].distance);
            unionRoot(root, v[i].node[0], v[i].node[1]);
        }
    }
    cout << endl;
    
    for (int i=0; i< v.size(); i++)to_string(v[i]);
    
    return answer;
}


int main() {
//    vector<int> s = {1, 9, 2, 3, 12, 10};
    
//  int result = solution({1, 2, 6, 8}, {1, 2, 5, 7});
    int result = solution({1, 2, 4, 2}, {1, 1, 4, 2});
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
