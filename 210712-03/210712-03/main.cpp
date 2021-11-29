//
//  main.cpp
//  210712-03
//
//  Created by 박경선 on 2021/07/12.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

long long solution(int w,int h) {
    return ((long)w * h) - ((long)w + h - gcd(w, h));
}

int main() {
    long long answer = solution(8, 12);
    
    int b[4][3];
    
    vector<int> dd ={} ;
    dd.back()
//    long long answer = solution(2, 2);
    
    cout << "answer : " << answer << endl;
    return 0;
}
