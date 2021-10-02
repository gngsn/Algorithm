//
//  main.cpp
//  210814-01
//
//  Created by 박경선 on 2021/08/14.
//
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fruitWeights, int k) {
    set<int> s;
    
    for (int i = 0; i < fruitWeights.size() - k + 1; i++) {
        vector<int> sub {fruitWeights.begin() + i, fruitWeights.begin()+k + i};
        int m = *max_element(sub.begin(), sub.end());
        
        cout << "sub "<< endl;
        for (int s : sub) {
            cout << s << " ";
        }
        cout << "\nm : "<< m << endl;
        s.insert(m);
    }
    
    vector<int> v;
//    vector<int> answer(s.end(), s.begin());
    return copy(s.begin(), s.end(), v.end());
}

int main(int argc, const char * argv[]) {
    vector<int> answer = solution({30, 40, 10, 20, 30}, 3);
    
    cout << "answer "<< endl;
    for (int a : answer) {
        cout << a << endl;
    }
    
    return 0;
}
