//
//  main.cpp
//  211013-01
//
//  Created by 박경선 on 2021/10/13.
//

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};

string ns(int n, int d) {
    string r = "";
    while(n != 0){
        r += number[n%d];
        n /= d;
    }
    reverse(r.begin(), r.end());
    return r;
}

string solution(int n, int t, int m, int p) {
    string answer="";
    string ent="0";
    int cnt=1, s=0;

    while (ent.size() < t*m) ent += ns(cnt++, n);
    cout << "ent : " << ent << endl;
    while (answer.size() < t && s < ent.size()) {
        answer += ent.substr(s, m)[p-1];
        s += m;
    }

    return answer;
}


int main() {
//    string result = solution(2, 50, 3, 1);
//    string result = solution(16, 16, 2, 1);
    string result = solution(16, 16, 2, 2);
    cout << "result : " << result << ", length : " << result.size() << endl;
    return 0;
}
