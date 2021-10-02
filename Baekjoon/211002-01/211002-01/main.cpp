//
//  main.cpp
//  211002-01
//
//  Created by 박경선 on 2021/10/02.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    map<int, int, greater<int>> p;
    
    for (int i=0; i < s.size(); i++)
        p[int(w[i]/t[i])] = i;
    
    for(auto it = p.begin(); it != p.end(); ++it) {
        int in = it -> second;
        long long weight = 0;
        if (a > 0) {
            weight = a > g[in] ? g[in] : a;
            a -= g[in];
        }
        if (b > 0) {
            weight += b > s[in] ? s[in] : b;
            b -= s[in];
        }
        long long  m = ceil((double)weight / w[in]);
        long long  time = t[in] * (2*m-1);
        if (answer < time) answer = time;
    }
    
    return answer;
}

int main() {
    long long result = solution(90, 500, {0,70,70}, {500,0,0}, {2, 100,100}, {1,4,8});
    cout << "\nresult : " << result << "\n";
    return 1;
}
