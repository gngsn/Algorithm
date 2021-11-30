//
//  main.cpp
//  211129-01
//
//  Created by 박경선 on 2021/11/29.
//

// 문제 : 영어 끝말잇기
// https://programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> m;
    char last;
    
    for (int i = 0; i < words.size(); i++) {
        if (m[words[i]] || (i > 0 && words[i][0] != last))
            return {(i % n) + 1, (i / n) + 1};
        m[words[i]] = true;
        last = words[i][words[i].size()-1];
    }

    return {0, 0};
}

int main(int argc, const char * argv[]) {
    vector<int> result = solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    cout << "번호 : " << result[0] << ", 차례 : " << result[ << endl;
    return 0;
}
