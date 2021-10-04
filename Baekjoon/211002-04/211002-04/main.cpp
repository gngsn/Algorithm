//
//  main.cpp
//  211002-04
//
//  Created by 박경선 on 2021/10/02.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int idx = 0;
    
    while (true) {
        if (idx == priorities.size()) idx = 0;
        cout << "\nidx : " << idx << endl;
        cout << "priorities : ";
        if (priorities[idx] == -1) {
            idx++;
            continue;
        }
        for (int r: priorities) {
            cout << r << " ";
        }
        
        int max = *max_element(priorities.begin(), priorities.end());
        if (priorities[idx] == max) {
            if (idx == location) break;
            priorities[idx] = -1;
            answer++;
        }
        idx++;
    }
    
    return answer;
}


int main() {
    int result = solution({2, 1, 3, 2}, 1);
    
    cout << "\nresult : " << result << endl;
    return 1;
}
