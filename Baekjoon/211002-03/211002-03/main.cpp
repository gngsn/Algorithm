//
//  main.cpp
//  211002-03
//
//  Created by 박경선 on 2021/10/02.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map<int, int> m;
    int last = 0;
    
    for (int i =0; i < progresses.size(); i++) {
        int hash = (double)(100-progresses[i]) / speeds[i];
        if (answer.empty() || last < hash) {
            answer.push_back(1);
            last = hash;
        }
        else
            ++answer.back();
    }
    
    return answer;
}


int main() {
    vector<int> result = solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1});
    
    cout << "\nresult : ";
    for (int r: result) {
        cout << r << " ";
    }
    return 1;
}
