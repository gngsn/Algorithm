//
//  main.cpp
//  210911-04
//
//  Created by 박경선 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};

string number_to_n(int num, int n){
    string result;
    if(num == 0){
        return "0";
    }
    while(num > 0){
        result += number[num % n];
        num /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool is_sosu(long num) {
    if (num < 2) return false;
    int a = (int) sqrt(num);
    for (int i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}

int c = 0;
void find_prime(string &n, int len, int s) {
    if (s+len > n.size()) return;
    string p = n.substr(s, len);
    while (is_sosu(stoi(p))) {
        
        
        p = n.substr(s, ++len);
        cout << "\n\np : " << p << endl;
        cout << "len : " << len << endl;
    }
    if(is_sosu(stol(p))) {
        cout << "p : " << p << endl;
        if ((s-1 >= 0 && n[s-1] == '0')||
            (s+len < n.size() && n[s+len] == '0')||
            (s-1 >= 0 && n[s-1] == '0' && s+len < n.size() && n[s+len] == '0')||
             s+len == n.size()+1) {
            cout << "counting " << endl;
            c++;
            n.replace(s, len, "0");
        }
    }
    find_prime(n, len, s+1);
}

int solution(int n, int k) {
    int answer = -1;
    int count = 0;
    string change = number_to_n(n, k);
    
    int s = 0, c = 1;
    vector<string> str;
    for (int i = 1; i < change.size(); i++) {
        find_prime(change, i, 0);
        cout << "change : " << change << endl;
    }
    cout << "c : " << c << endl;
    return answer;
}

int main() {
    int result = solution(437674, 3);
    
    cout << "result : " << result << endl;
    return 0;
}
