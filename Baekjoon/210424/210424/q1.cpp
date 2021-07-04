//
//  q1.cpp
//  210424
//
//  Created by 박경선 on 2021/04/24.
//

#include <stdio.h>
#define MAX_NUM=300
using namespace std

//template<typename T>

string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}


int main() {
    
}
