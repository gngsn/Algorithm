//
//  main.cpp
//  211120-01
//
//  Created by 박경선 on 2021/11/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printvector(vector<T> arr) {
    cout << "arr : ";
    for (int a: arr) {
        cout << a;
    }
//    for (int i=0;i<arr.size(): i++) {
//        cout << arr[i];
//    }
//    for (auto iter=arr.begin(); iter != arr.end(); iter++) {
//        cout << *iter;
//    }
    cout << endl;
}

string fun(vector<int> arr) {
    printvector(arr);
    return "test";
}

int main() {
    string result = fun({1,2,3});
        
    cout << result << endl;
    return 0;
}
