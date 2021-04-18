//
//  42587.cpp
//  level1
//
//  Created by 박경선 on 2021/02/24.
//

#include "print.cpp"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class q42587 {
    
    int solution(vector<int> priorities, int location) {
        queue<int> printer;                         //queue에 index 삽입.
        vector<int> sorted;                         //정렬된 결과 저장용
        for(int i=0; i<priorities.size(); i++) {
            printer.push(i);
        }
        while(!printer.empty()) {
            int now_index = printer.front();
            printer.pop();
            if(priorities[now_index] != *max_element(priorities.begin(),priorities.end())) {
                //아닌경우 push
                printer.push(now_index);
            } else {
                //맞는경우
                sorted.push_back(now_index);
                priorities[now_index] = 0;
            }
        }
        for(int i=0; i<sorted.size(); i++) {
            if(sorted[i] == location) return i+1;
        }
        return 0;
    }

    int main() {
        //    ios::sync_with_stdio(0);
        //    cin.tie(NULL); cout.tie(NULL);
            
            vector<int> priorities = {2, 1, 3, 2};
            int location = 2;
            
        //    vector<int> priorities2 = {1, 1, 9, 1, 1, 1};
        //    int location2 = 0;
            
            int answer = solution(priorities, location);
        //    int answer = solution(priorities2, location2);
            cout << "answer : " << answer << "\n";

            return 0;
    }
};
