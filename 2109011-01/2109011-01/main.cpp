//
//  main.cpp
//  2109011-01
//
//  Created by 박경선 on 2021/09/11.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> student, int k) {
    int count = 0;
    
    for (auto i = 0; i < student.size(); i++) {
        int _k = k;
        for (auto j = i; j < student.size(); j++) {
            if (student[j] == 1) _k--;
            if (_k == 0) count++;
        }
    }
    cout << "count: " << count << endl;
    
    return count;
}


int main() {
//    int result = solution({0,1,0,0}, 1);
//    int result = solution({0, 1, 0, 0, 1, 1, 0}, 2);
//    int result = solution({0, 1, 0}, 2);
    int result = solution({1}, 1);
    cout << "result : " << result << endl;
    return 0;
}

template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}
