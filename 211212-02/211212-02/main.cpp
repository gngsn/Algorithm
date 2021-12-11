//
//  main.cpp
//  211212-02
//
//  Created by 박경선 on 2021/12/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int R) {
    int max = 0;
    if (A.size() == R) return 0;
    
    for (int i =0; i+R < A.size(); i++) {
        set<int> s(A.begin() + (i+R), A.end());
        cout << "start : "<< i << ", end : " << (i+R-1) << endl;

        for (auto it = s.begin(); it != s.end(); ++it)
            cout << ' ' << *it;

        cout << endl;
        if (s.size() > max) max = s.size();
    }

    return max;
}



int main() {
//    vector<int> s = ([2, 1, 2, 3, 2, 2], 3)
    int result = solution(s, 15);
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
