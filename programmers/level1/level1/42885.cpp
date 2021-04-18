//
//  42885.cpp
//  level1
//
//  Created by 박경선 on 2021/02/25.
//

#include "print.cpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class q42885 {
    int solution(vector<int> people, int limit) {
        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());
        int N = (int)people.size();
        int answer = 0;
        for (int i = 0, j = N - 1; i <= j; i++) {
            if (people[i] + people[j] <= limit) {
                j--;
            }
            answer++;
        }
        return answer;
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(NULL); cout.tie(NULL);
        
        vector<int> people = {70, 50, 80, 50};
        int limit = 100;
        
        vector<int> people2 = {70, 80, 50};
        vector<int> people3 = {20, 20, 30, 40, 50, 100};
        vector<int> people4 = {40, 40, 40};

        int answer = solution(people, limit);
        cout << "\n\n answer : " << answer << endl;

        return 0;
    }

};
