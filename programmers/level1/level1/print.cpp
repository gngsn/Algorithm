//
//  printVector.cpp
//  level1
//
//  Created by 박경선 on 2021/02/23.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}


template<typename T>
string print_stack (stack<T> st, bool is_inverse = false) {
    string str = "";
    while(!st.empty()){
        str = is_inverse ? to_string(st.top()) + str : str + to_string(st.top());
        st.pop();
    }
    return str;
}
