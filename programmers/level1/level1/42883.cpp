//
//  42883.cpp
//  level1
//
//  Created by 박경선 on 2021/02/24.
//

#include "print.cpp"
#include <iostream>
#include <stack>

using namespace std;

class q42883 {
    string solution(string number, int k) {
        string answer = "";
        stack<int> st;
        st.push(number[0] - '0');
        
        for (int i = 1; i < number.size(); i++) {
            while (k > 0 && !st.empty() && number[i] - '0' > st.top()) {
                st.pop();
                k--;
            }
            st.push(number[i] - '0');
        }
        
        while (k > 0) {
            st.pop();
            k--;
        }
        
        while(!st.empty()){
            answer = to_string(st.top()) + answer;
            st.pop();
        }
        
        return answer;
    }


    int main() {
        ios::sync_with_stdio(0);
        cin.tie(NULL); cout.tie(NULL);
        
        string number = "1924";
        int k = 2;
        
        string number2 = "1231234";
        int k2 = 3;
        
        string number3 = "4177252841";
        int k3 = 4;
        
        
        string answer = solution(number3, k3);
        cout << "\nanswer : " << answer << endl;

        return 0;
    }
};
