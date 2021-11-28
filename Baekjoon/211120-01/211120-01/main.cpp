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
#include <set>
#include <cmath>
#include <chrono>
#include <time.h>

using namespace std;
using namespace chrono;

template <typename T>
void printvector(vector<T> arr) {
    cout << "arr : ";
    for (T a: arr) {
        cout << a << " ";
    }
//    for (int i=0;i<arr.size(): i++) {
//        cout << arr[i];
//    }
//    for (auto iter=arr.begin(); iter != arr.end(); iter++) {
//        cout << *iter;
//    }
    cout << endl;
}

template <typename T>
void printset(set<T> arr) {
    cout << "arr : ";
    for (T a: arr) {
        cout << a << " ";
    }
//    for (int i=0;i<arr.size(): i++) {
//        cout << arr[i];
//    }
//    for (auto iter=arr.begin(); iter != arr.end(); iter++) {
//        cout << *iter;
//    }
    cout << endl;
}

int ans = 0;

bool isPrime(int n) {
    if(n < 2) return false;

    for(int i = 2; i <= sqrt(n); i++) {
        if((n % i) == 0) {
            return false;
        }
    }

    return true;
}

// Time difference = 136[ms]
// Time difference = 30[ms]
void find(vector<int> nums, int idx, int cnt, int sum) {
    if (cnt == 3 && isPrime(sum)) {
        ans++;
        return;
    }
    if (cnt < 3 && cnt > nums.size() - idx - 1) return;
    
    if (idx+1 <= nums.size()) {
        find(nums, idx+1, cnt+1, sum+nums[idx]);
        find(nums, idx+1, cnt, sum);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    clock_t begin = clock();
//    find(nums, 0, 0, 0);
    for(int i=0;i<nums.size()-2;i++)
        for(int j=i+1;j<nums.size()-1;j++)
            for(int k=j+1;k<nums.size();k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if(isPrime(sum)) answer++;
            }
    clock_t end = clock();
    cout << "Time difference = " << (double)(end - begin) << "[ms]" << endl;

    return answer;
}

int main() {
//    int result = solution({1,2,3,4});
    int result = solution({1,2,7,6,4});
    
    cout << result << endl;
    return 0;
}
