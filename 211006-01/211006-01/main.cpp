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
        if(isPrime(stoi(comb)) && !m[comb]) m[comb] = 1;
        cout << comb << endl;
    } else if (depth == arr.size()) {
        return;
    } else {
        comb[index] = arr[depth];
        if (comb[0] != '0')
            combination(arr, comb, r - 1, index + 1, depth + 1);
        combination(arr, comb, r, index, depth + 1);
    }
}

void swap(char & a, char & b) {
    char temp = a;
    a = b;
    b = temp;
}

void permutation(char data [], int depth, int n, int r) {
    if (depth == r) {
        for(int i = 0; i < r; i++)
            cout << data[i] << " ";
        cout << endl;
        
        return;
    }
    
    for(int i = depth; i < n; i++) {
        swap(data[depth], data[i]);   // 스왑
        permutation(data, depth + 1, n, r);  // ⭐재귀
        swap(data[depth], data[i]);  // 다시 원래 위치로 되돌리기
    }
}

bool match(string numbers, int n) {
//    if (n == 1 && numbers)
    return false;
}

int solution(string numbers) {
    int answer = 0;
    string com = "aaa";
    char arr [] = {'a', 'b', 'c', 'd'};
       
   permutation(arr, 0, 4, 3); // 4P3

//    combination(numbers, com, 3, 0, 0);
    
    for (auto it = m.begin(); it != m.end(); it++)
        cout << "key : " << it->first << " ";
//    for (int i =0; i<numbers.size(); i++) {
//        match(numbers, i);
//    }
    
    return answer;
}


int main() {
    int result = solution("012031");
    cout << "\nresult : " << result << endl;
    return 1;
}
