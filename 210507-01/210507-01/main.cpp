//
//  main.cpp
//  210507-01
//
//  Created by 박경선 on 2021/05/07.
//

#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    string calc = "+-*";
    regex re("["+calc+"]");
    for (int i=0; i<expression.size(); i++) {
        if (!isalpha(expression[i])) {
            
        }
    }
    
    return answer;
}

int main() {
    string expression = "100-200*300-500+20";
    long long result = solution(expression);
    cout << "result : " << result;
    return 0;
}
