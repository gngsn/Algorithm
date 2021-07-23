//
//  main.cpp
//  210719-01
//
//  Created by 박경선 on 2021/07/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

string setHand(int n,int &hand, string value) {
    hand = n;
    return value;
}

pair<int, int> getCoord(int n) {
    int x = n % 3 != 0 ? n/3 : n/3-1;
    int y = n % 3 != 0 ? n%3-1 : 2;
    cout << "getcoord - n : " << n << ", x : " << x << ", y : " << y << endl;
    return {x, y};
}

string whichis(int n, int &lh, int &rh, string hand) {
    pair<int, int> nc = getCoord(n);
    pair<int, int> lc = getCoord(lh);
    pair<int, int> rc = getCoord(rh);
    double distL = sqrt(pow(nc.first-lc.first, 2) + pow(nc.second-lc.second, 2));
    double distR = sqrt(pow(nc.first-rc.first, 2) + pow(nc.second-rc.second, 2));
    cout << "whichis - distL : " << distL << ", distR : " << distR << endl;
    if (distL == distR) {
        if (hand == "right") return setHand(n, rh, "R");
        else return setHand(n, lh, "L");
    } else if (distL < distR) return setHand(n, lh, "L");
    else return setHand(n, rh, "R");
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lh = 10, rh = 12;
    
    for (int n : numbers) {
        if (n == 0) n = 11;
        
        cout << "\nn : " << n << ", lh : " << lh << ", rh : " << rh << endl;
        
        if (n % 3 == 1) answer += setHand(n, lh, "L");
        if (n % 3 == 0) answer += setHand(n, rh, "R");
        if (n % 3 == 2) answer += whichis(n, lh, rh, hand);
        cout << "answer : " << answer << endl;
    }
    
    return answer;
}

int main() {
    string answer = solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
//    LRLLLRLLRRL
//    LRLLLRLLLRL
    cout << "answer : " << answer << endl;
    return 0;
}
