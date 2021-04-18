//
//  print.cpp
//  Baekjoon
//
//  Created by 박경선 on 2021/03/02.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
string print_vector(vector<T> vec) {
    string str;
    for (T v: vec)
        str += to_string(v) + ' ';
    return str;
}
