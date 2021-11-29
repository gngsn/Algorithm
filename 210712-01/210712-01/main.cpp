//
//  main.cpp
//  210712-01
//
//  Created by 박경선 on 2021/07/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;
long long MAX = 0;

int calc(int a, int b, char exp) {
    int r = 0;
    if (exp == '+') r =  a + b;
    else if (exp == '-') r = a - b;
    else r = a * b;
    return r;
}

void parseExp(vector<string> nums, string seq) {
    long long sum = 0;
    while(nums.size() > 1 && seq.size() > 0) {
        string s = "";
        auto it = find(nums.begin(), nums.end(), s+seq[0]);
        while (it != nums.end()) {
            auto idx = distance(nums.begin(), it);
            int r = calc(stoi(nums.at(idx-1)), stoi(nums.at(idx+1)), nums.at(idx)[0]);
            for(int i = 3; i > 0; i--) nums.erase(it-1);
            nums.insert(it-1, to_string(r));
            it = find(nums.begin(), nums.end(), s+seq[0]);
        }
        seq = seq.substr(1, seq.size());
    }
    sum = stoll(nums[0]);
    if (abs(sum) > MAX) MAX = abs(sum);
}

long long solution(string expression) {
    long long answer = 0;
    string num = "";
    vector<string> exp;
    vector<string> seq = {"*+-", "*-+", "+-*", "+*-", "-+*", "-*+"};
    
    for (char c : expression) {
        if (c -'0' > -1) {
            num += c;
            continue;
        }
        exp.push_back(num);
        num = "";
        exp.push_back(num+c);
        num = "";
    }
        
    if (num != "") exp.push_back(num);
    
    for (string s: seq) {
        parseExp(exp, s);
    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
//    solution("100-200*300-500+20");
//    solution("200-300-500-600*40+500+500");
    solution("2*2*2*2*2-2*2*2");
    
    cout << "MAX : " << MAX << endl;
    return 0;
}



//        cout << "map: ";
//        for(auto it = nums.cbegin(); it != nums.cend(); ++it) {
//            cout << " " << it->first << ", " << it->second;
//        }
//        cout << endl;
