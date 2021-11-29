//
//  main.cpp
//  211004-01
//
//  Created by 박경선 on 2021/10/04.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



int solution(string str1, string str2) {
    vector<string> s2;
    int INTER = 0;
    int UNION = 0;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for (int i=1; i < str2.size(); i++)
        if (isalpha(str2[i-1]) > 0 && isalpha(str2[i]) > 0)
            s2.push_back(str2.substr(i, 2));
    
    for (int i=1; i < str1.size(); i++) {
        if (isalpha(str1[i-1]) < 1 || isalpha(str1[i]) <1) continue;
        auto it = find(s2.begin(), s2.end(), str1.substr(i, 2));
        if (it != s2.end()) {
            INTER++;
            s2.erase(it);
        }
        UNION++;
    }
    if (!s2.empty()) UNION += s2.size();
    return INTER > 0 && UNION > 0 ? floor((double)INTER * 65536/UNION) : 65536;
}

int main() {
//    int result = solution("FRANCE", "french");
//    int result = solution("FRANCE", "");
    int result = solution("aa1+aa2", "AAAA12");
//    int result = solution("E=M*C^2", "e=m*c^2");
//    int result = solution("handshake", "shake hands");
    
    
    cout << "result : " << result << endl;
    return 0;
}
