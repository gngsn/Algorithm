//
//  main.cpp
//  2109011-02
//
//  Created by 박경선 on 2021/09/11.
//
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


string solution(vector<string> research, int n, int k) {
    string answer = "";
    int issue_margin = 2 * k * n;
    int issue_count = 0;
    map<char, int> days[research.size()];
    set<char> keys;
    
    for (int d = 0; d < research.size(); d++) {
        string res = research[d];
        map<char, int> keyword;
        for (int i = 0; i < res.size(); i++) {

            keys.insert(res[i]);
            size_t n = count(res.begin(), res.end(), res[i]);
            keyword[res[i]] = n;
        }
        days[d] = keyword;
    }
    
    for (char key: keys) {
        cout<<"\n";
        int count=0;
        for (int d = 0; d < research.size(); d++) {
            int value=0;
            cout<<"- key : " << key <<endl;
            for (int i = d; i < research.size() && i < d+n; i++) {
                map<char, int> day = days[i];
                if (day.find(key) == day.end() && day[key] < k) continue;
                cout<<"- d : " << d <<" Key : "<< key <<", Value : "<<day[key]<<endl;
                value += day[key];
                count++;
            }
            cout<<"-- value : " << value <<endl;
            cout<<"-- count : " << count <<endl;
            
            if (value >= issue_margin) {
                if(count > issue_count) {
                    issue_count = count;
                    answer = "";
                    answer += key;
                } else if (answer == "") {
                    answer += key;
                }
            }
            if (value >= issue_margin && answer == "") answer += key;
        }
    }
    cout<<"-- answer : " << answer <<endl;
    return answer == "" ? "None" : answer;
}

int main() {
//    string result = solution({"abaaaa","aaa","abaaaaaa","fzfffffffa"}, 2, 2);
//    string result = solution({"yxxy","xxyyy"}, 2, 1);
    string result = solution({"yxxy", "xxyyy", "yz"}, 2, 1);
    cout << "result : " << result << endl;
    return 0;
}

template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}
