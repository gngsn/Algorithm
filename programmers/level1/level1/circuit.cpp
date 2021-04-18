//
// Created by 박경선 on 2021/02/22.
//

#include <iostream>
#include <iterator> // for iterators
#include <vector> // for vectors

using namespace std;

int usingIterator(vector<int> arr) {
    vector<int>::iterator ptr;

    cout << "usingIterator - The vector elements are : ";
    for (ptr = arr.begin(); ptr < arr.end(); ptr++)
        cout << *ptr << " ";

    return 0;
}

int usingSize(vector<int> arr) {
    cout << "usingSize - The vector elements are : ";
    for (size_t i = 0; i< arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

int usingAuto(vector<int> arr) {
    cout << "usingAuto - The vector elements are : ";
    for (int emt : arr) {
        cout << emt << " ";
    }
    return 0;
}

int usingPointer(vector<int> arr) {
    cout << "usingPointer - The vector elements are : ";
    int num = 0;
    int* arr_first = &arr[0];
    for (size_t i = 0; i < arr.size(); i++) {
        num = *(arr_first + i);
        cout << num << " ";
    }
    return 0;
}

int circuit() {
//    vector<int> ar = { 1, 2, 3, 4, 5 };

//    이 아래는 거의 똑같음
//    usingIterator(ar);
//    usingSize(ar);
//    usingAuto(ar);
    
//    포인터를 사용하는게 가장 빠르다.
//    usingPointer(ar);
    return 0;
}
