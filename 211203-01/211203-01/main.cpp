//
//  main.cpp
//  211203-01
//
//  Created by 박경선 on 2021/12/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
typedef long long lo;

using namespace std;

bool compare(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), compare);
    int end = routes[0][1];
    
    for (int i = 1; i < routes.size(); i++) {
        for(int d: routes[i]) cout << d << " ";
        cout << endl;
        if (routes[i][0] > end) {
            end = routes[i][1];
            answer++;
        } else if (routes[i][1] < end) {
            end = routes[i][1];
        }
    }
    return answer;
}


int main(int argc, const char * argv[]) {
//    int re = solution({{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}});
    int result = solution({{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}, {1, 3}, {2, 3}, {2, 2}, {3, 5}});
    cout << "result : " << result << endl;
    return 0;
}
