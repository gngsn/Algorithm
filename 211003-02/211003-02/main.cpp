//
//  main.cpp
//  211003-02
//
//  Created by 박경선 on 2021/10/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>

using namespace std;

template<typename T>
void print_vector(vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        cout << *(v_first + i) + " ";
}

//vector<string> pos;
map<string, int> pos;
map<int, int> m;

void comb(string s, string c, int r, int idx) {
    if (idx > s.size()) return;
    if (r == 0) {
        if (pos.find(c) == pos.end()) pos[c] = 1;
        else pos[c]++;
        
        if (m[c.size()] < pos[c]) m[c.size()] = pos[c];
        return;
    }
    
    comb(s, c + s[idx], r - 1, idx+1);
    comb(s, c, r, idx+1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    deque<int> d;
    
    d.
    for (string o: orders)
        for (int c: course)
            comb(o, "", c, 0);

    for(auto iter = m.begin(); iter != m.end() ;iter++)
        cout<<"m size : "<< iter->first <<", count : "<<iter->second<<endl;
    
    for(auto iter = pos.begin(); iter != pos.end() ;iter++) {
        cout<<"Key : "<< iter->first <<", size : " << iter->first.size() <<
        ", m: "<< m[iter->first.size()] << ", Value : "<<iter->second<<endl;
        
        if (iter->second > 1 && iter->second == m[iter->first.size()]) {
            cout<<"first.size : "<< iter->first.size() << ", m[size] : " <<m[iter->first.size()] << endl;
            answer.push_back(iter->first);
        }
    }
    
    return answer;
}

int main() {
//    vector<string> result = solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2,3,4});
    vector<string> result = solution({"XYZ", "XWY", "WXA"}, {2,3,4});
    
    cout << "\nresult : ";
    print_vector(result);
    return 1;
}
