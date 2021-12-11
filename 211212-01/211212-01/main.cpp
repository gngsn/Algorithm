//
//  main.cpp
//  211212-01
//
//  Created by 박경선 on 2021/12/12.
//

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string S, vector<string> L) {
    map<char, int> word;
    int max = 0;

    for (int i=0; i < S.size(); i++) {
        word[S[i]] = word.find(S[i]) != word.end() ? word[S[i]]+=1 : 1;
    }

    for (int i=0; i < L.size(); i++) {
        map<char, int> cnt;
        int avail = S.size();
        for (int j=0; j < L[i].size(); j++) {
            cnt[L[i][j]] = cnt.find(L[i][j]) != cnt.end() ? cnt[L[i][j]]+=1 : 1;
        }

        for(auto iter = cnt.begin(); iter != cnt.end() ;iter++) {
            int c = word[iter->first] / iter->second;
            if (avail > c) avail = c;
        }
        if (avail > max) max = avail;
    }
    return max;
}


int main() {
    string s = "";
    vector<string> L = {};
    
    
    int result = solution("BILLOBILLOLLOBBI", {"BILL", "BOB"});
//    int result = solution("CAT", {"ILOVEMYDOG", "CATS"});
//    int result = solution("ABCDXYZ", {"ABCD", "XYZ"});
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
