//
//  main.cpp
//  211203-02
//
//  Created by 박경선 on 2021/12/03.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;

ll solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll low = 0, high = times.back() * n;
    
    while (low != high) {
        ll mid = (low + high) / 2;
        ll pos = 0;
        for (int t: times) pos += mid / t;
        if (pos >= n) high = mid;
        else low = mid + 1;
    }
    
    return low;
}

int main(int argc, const char * argv[]) {
//    ll result = solution(6, {7, 10});
    ll result = solution(60, {3, 4, 4, 6, 10});
    cout << "result : " << result << endl;
    return 0;
}
