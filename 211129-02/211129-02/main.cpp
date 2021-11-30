//
//  main.cpp
//  211129-02
//
//  Created by 박경선 on 2021/11/29.
//

// 문제 : 기지국 설치
// https://programmers.co.kr/learn/courses/30/lessons/12979

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0, start = 1;
    
    for (int i=0; i < stations.size(); i++) {
        if (start < stations[i]-w)
            answer += ceil(double((stations[i]-w) - start) / double(2*w+1));
        start = stations[i]+w+1;
    }

    if (start < n+1) answer += ceil(double(n+1 - start) / double(2*w+1));
        
    return answer;
}

int main() {
    int result = solution(11, {4, 11}, 1);
    cout << "result : " << result << endl;
    return 0;
}
