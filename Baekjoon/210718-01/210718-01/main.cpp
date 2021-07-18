//
//  main.cpp
//  210718-01
//
//  Created by 박경선 on 2021/07/18.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> pos;
    int weight = 0;
    pos[0][0] = weight++;
    
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (i == 0) {
                pos[i][j] = pos[i][j-1];
                continue;
            }
            if (j == 0)
                pos[i][j] = weight;
            pos[i][j] = pos[i][j-1] > pos[i-1][j] ? pos[i-1][j]: pos[i][j];
            weight++;
        }
    }
    return answer;
}

int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
