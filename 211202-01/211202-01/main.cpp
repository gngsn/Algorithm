//
//  main.cpp
//  211202-01
//
//  Created by 박경선 on 2021/12/02.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(char ine, int dis, int cond) {
    if (ine == '=') {
        return dis == cond;
    } else if (ine == '>') {
        return dis > cond;
    } else {
        return dis < cond;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do {
        for (string d: data) {
            char f1 = d[0], f2 = d[2];
            n = d[4] - '0';
            int dist = friends.find(f1) - friends.find(f2);
            if (!check(d[3], abs(dist)-1, n)) goto next;
        }
        answer++;
        next: {}
    } while (next_permutation(friends.begin(), friends.end()));
    
    return answer;
}

int main() {
    int result = solution(2, {"N~F=0", "R~T>2"});
    cout << "result : " << result << endl;
    return 0;
}
