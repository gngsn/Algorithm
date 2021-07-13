//
//  main.cpp
//  210712-02
//
//  Created by 박경선 on 2021/07/12.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    if (s.size() == 1) answer = 1;
    for (int i = 1; i < s.size(); i++) {
        if (i > answer) break;
        string a = "";
        int pos = 0;
        while(pos+i < s.size()) {
            int count = 1;
            string base = s.substr(pos, i);
            while (base == s.substr(pos+i, i)) {
                count++;
                pos = pos+i;
//                cout << "base : " << base << ", pos : " << pos << ", pos+i : " << (pos+i) << endl;
            }
            pos += i;
            a += count < 2 ? base : to_string(count) + base;
        }
        a += s.substr(pos, s.size() - a.size());
        if (a.size() < answer) {
            cout << "a : " << a << endl;
            answer = a.size();
            
        }
    }
    return answer;
}
int main() {
//    int answer = solution("xxxxxxxxxxyyy");
//    int answer = solution("aabbaccc");
//    int answer = solution("abcabcabcabcdededededede");
    int answer = solution("a");
    
    cout << "answer : " << answer << endl;
    return 0;
}
