//
//  main.cpp
//  210716-01
//
//  Created by 박경선 on 2021/07/16.
//

#include <iostream>
#include <string>
#include <vector>
//#include <set>
#include <unordered_set>

using namespace std;
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> pos(9);
    
    for (int i=1; i<=8;i++) {
        string s(i, N + '0');
        pos[i].insert(stoi(s));
        if (stoi(s) == number) answer = i;
        if (answer > 0) break;
        for (int l=1; l<i; l++) {
            for (int a : pos[l]) {
                for (int b : pos[i-l]) {
                    if (a+b == number || a-b == number || a*b == number || (b!=0 && a/b == number))
                        answer = i;
                    pos[i].insert(a+b);
                    pos[i].insert(a-b);
                    pos[i].insert(a*b);
                    if (b != 0) pos[i].insert(a/b);
                }
            }
        }
    }
    
    return answer;
}


int main() {
//    int answer = solution(5, 12);
//    int answer = solution(2, 11);
    int answer = solution(2, 2);
    
    cout << "answer : " << answer << endl;
    return 0;
}
