//
//  main.cpp
//  211001-01
//
//  Created by 박경선 on 2021/10/01.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string W, S;

bool match(int w, int s) {
    while ((w < W.size() && s < S.size()) && (W[w] == '?' || W[w] == S[s])) {
        w++;
        s++;
    }
    if (w == W.size()) return s == S.size();
    if (W[w] == '*')
        while(s < S.size() && W[w+1] != S[s]) s++;
    
    return match(w+1, s);
}

int main() {
    int c;
    cin >> c;
    vector<string> answer;
    
    for (int i = 0; i < c; i++) {
        cin >> W;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> S;
            if(match(0, 0))
                answer.push_back(to_string(i) +": "+S);
        }
    }
    
    sort(answer.begin(), answer.end());
    for (string a : answer)
        cout << a << "\n";
    
    return 0;
}
