//
//  main.cpp
//  211006-01
//
//  Created by 박경선 on 2021/10/06.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

bool isPrime(int n) {
    if(n<=1)return false;

    for(int i=2; i<=sqrt(n); i++) {
        if((n%i)==0) {
            return false;
        }
    }

    return true;
}

map<string, int> m;
void combination(string arr, string comb, int r, int index, int depth) {
    if (r == 0) {
        for(int i = 0; i < comb.size(); i++)
            cout << comb[i] << " ";
        cout << endl;
    }
    else if (depth == arr.size()) {
        return;
    }
    
    else {
        comb[index] = arr[depth];
        combination(arr, comb, r - 1, index + 1, depth + 1);
        combination(arr, comb, r, index, depth + 1);
    }
}

bool match(string numbers, int n) {
//    if (n == 1 && numbers)
    return false;
}

int solution(string numbers) {
    int answer = 0;
    combination(numbers, "", 3, 0, 0);
    for (int i =0; i<numbers.size(); i++) {
//        match(numbers, i);
        
    }
    
    return answer;
}


int main() {
    int result = solution("01231");
    cout << "\nresult : " << result << endl;
    return 1;
}
