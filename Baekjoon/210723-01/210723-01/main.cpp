//
//  main.cpp
//  210723-01
//
//  Created by 박경선 on 2021/07/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> s;
    int start = 0, end = 0;
    
    for (int i =0; i< gems.size();i++) {
        auto it = s.find(gems[i]);
        if (it == s.end()) {
            end = i;
            s.insert(gems[i]);
        }
    }
    cout << "end : " << gems[end] << ", index : " << end << endl;
    
    while (end < gems.size()) {
        auto it = find(gems.begin()+start+1, gems.begin()+end, gems[start]);
        if (it == gems.begin()+end) break;
        start++;
    }
    
    cout << "start : " << gems[start] << ", index : " << start << endl;
    
    
    return {start+1, end+1};
}


int main() {
//    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
//    vector<int> answer = solution(gems);
//    vector<int> answer = solution({"AA", "AB", "AC", "AA", "AC"});
    vector<int> answer = solution({"AA"});
    
    
    cout << "answer : ";
    for (int a:answer)
        cout << a << " ";
    cout << endl;
    
    return 0;
}
