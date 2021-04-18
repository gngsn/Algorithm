//
// Created by 박경선 on 2021/02/22.
//

#include <iostream>
#include <iterator> // for iterators
#include <vector> // for vectors

using namespace std;

int usingIterator(vector<int> arr) {
    vector<int>::iterator ptr;

    cout << "The vector elements are : ";
    for (ptr = arr.begin(); ptr < arr.end(); ptr++)
        cout << *ptr << " ";

    return 0;
}

int main() {
    vector<int> ar;
    // ar = { 1, 2, 3, 4, 5 };
    usingIterator(ar);
}