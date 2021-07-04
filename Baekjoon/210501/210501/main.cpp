//
//  main.cpp
//  210501
//
//  Created by 박경선 on 2021/05/01.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int abs (int a, int b) {
    return a > b? a-b:b-a ;
}

int solution(string inputString) {
    vector<char> stack;
    bool check = false;
    vector<int> open = {'(', '{', '[', '<'};
    vector<int> close = {')', '}', ']', '>'};
    
    for(int i=0; i < inputString.size(); i++) {
        auto openit = find(open.begin(), open.end(), inputString[i]);
        if (openit != open.end()) {
            stack.push_back(inputString[i]);
            check = true;
        }
        
        auto closeit = find(close.begin(), close.end(), inputString[i]);
        if (closeit != close.end()) {
            if (stack.size() < 1) return i;
            char t = stack.back();
            stack.pop_back();
            
            if (abs(inputString[i] -'0', t - '0') > 2) return -i;
            check = true;
        }
    }
    if (stack.size() != 0) return -(inputString.size()-1);
    else return check ? 0 : 1;
}


int main(int argc, const char * argv[]) {
    int s = solution("line [({<plus>)}]");
//    int s = solution("line [({<plus>})");
//    int s = solution(">_<");
//    int s = solution("x * (y + z) ^ 2 = ?");
    
    
    
    cout << "answer : " << s << endl;
    return 0;
}
