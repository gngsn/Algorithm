//
//  main.cpp
//  211211-01
//
//  Created by 박경선 on 2021/12/11.
//

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<vector<int>> needs, int r) {
    int answer = 0;
    vector<int> sum(needs.size(), 0);
    map<int, set<int>> m;
    priority_queue<pair<int, int>> pq;
    
//    for (int i =0; i< needs.size(); i++) {
//        for (int j =0; j < needs[i].size(); j++) {
//            sum[j] += needs[i][j];
//            m[j].insert(i);
//        }
//    }
//
//    for (int i = 0; i < sum.size(); i++) pq.push({sum[i], i});
//
//    for (int j =0; j < r; j++) {
//        answer += pq.top().first;
//        pq.pop();
//    }
    return answer;
}

int main() {
    vector<vector<int>> s = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}, {1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = solution(s, 2);
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
