//
//  main.cpp
//  211210-01
//
//  Created by 박경선 on 2021/12/10.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int low=0, high=distance;
    vector<int> dist;
    
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    while (low < high) {
        int mid = (low+high) / 2;
        int remove = 0, start = 0;
        cout << endl;
        cout << "mid : " << mid << endl;
        for (int roc: rocks) {
            if (roc - start < mid) {
                remove++;
                cout << roc << " ";
            } else start = roc;
        }
        cout << endl;
        
        if (remove <= n) {
            low = mid + 1;
            if (mid > answer) answer = mid;
        } else high = mid;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> s = {2, 14, 11, 21, 17};
    int result = solution(25, s, 2);
    cout << "\nresult : " << result << endl;

    return 0;
}
