//
//  main.cpp
//  211204-01
//
//  Created by 박경선 on 2021/12/04.
//

#include <iostream>
#include <string>
#include <vector>
#define INF 2e9

using namespace std;

vector<bool> visited;

template<typename T>
void print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        cout << to_string(*(v_first + i)) + " ";
}

void visit(vector<int> inputs, vector<int> dp, int idx) {
//    if ()
        
    for (int i=2; idx+i < inputs.size(); i++) {
        if (dp[idx] < inputs[idx] + inputs[idx-i])
//        visit(inputs, dp, idx+i);
    }
}

int solution(vector<int> inputs) {
    int answer = 0;
    vector<int> dp;
    dp.resize(inputs.size(), 0);
    
    
    for (int i = 0; i<inputs.size(); i++) {
        visited.resize(inputs.size(), false);
        visit(inputs, dp, i);
    }
    
    
    return answer;
}

int main() {
    vector<int> inputs;
    int n;
    cin >> n;
            
    for(int i=0; i<n; i++){
        int storage;
        cin >> storage;
        inputs.push_back(storage);
    }
    
    int result = solution(inputs);
    cout << "\nresult : " << result << endl;
    return 1;
}

/*
 
 4
 1 3 1 5
 */
