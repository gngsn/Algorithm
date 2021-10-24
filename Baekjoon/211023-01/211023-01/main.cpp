//
//  main.cpp
//  211023-01
//
//  Created by 박경선 on 2021/10/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    map<int, set<pair<int, int>>> crd;
    int answer=0, ns=0, end=0, area=0;
    vector<int> st;
     
    for (vector<int> t: track) {
        crd[t[0]].emplace(t[1], t[2]);
    }
    

    for (auto &cset : crd) {
        ns=0; end=0;
        for (pair<int, int> p: cset.second) {
            if(end >= p.second) continue;
            ns = ns <= end ? ns=end+1 : p.first;
            end = max(p.second, ns-1);
            cout << "ns : " << ns << ", end: "<< end << endl;
            answer += end - ns + 1;
        }
        cout << "answer : " << answer << endl;
    }
    
    return n*m-answer;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> track = {
        {2, 2, 3},
        {2, 6, 7},
        {3, 1, 4},
        {3, 3, 6},
        {3, 2, 3},
        {4, 4, 4},
        {4, 5, 5},
        {4, 6, 6},
        {5, 7, 7},
        {6, 1, 1},
        {7, 1, 7},
    };
    int result = gridlandMetro(7, 7, 7, track);
    cout << "result : " << result;
    return 0;
}
