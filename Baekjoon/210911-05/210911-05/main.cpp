//
//  main.cpp
//  210911-05
//
//  Created by 박경선 on 2021/09/11.
//

#include <iostream>
#include <vector>

using namespace std;

string solution(string a) {
    return "sdf";
}

int main() {
    string result = solution("");
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
