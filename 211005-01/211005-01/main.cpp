//
//  main.cpp
//  211005-01
//
//  Created by 박경선 on 2021/10/05.
//

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> p) {
    unordered_map<string, int> m;
    for (int i = 0; i < p.size(); i++) m[p[i]] = 1;
    for (int i = 0; i < p.size(); i++)
        for (int j = 0; j < p[i].size(); j++)
            if (m[p[i].substr(0, j)]) return false;
    return true;
}

int main() {
    bool result = solution({"119", "97674223", "1195524421"});
//    bool result = solution({"123","456","789"});
    
    cout << "result : " << result << endl;
    return 0;
}
