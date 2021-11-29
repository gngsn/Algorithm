//
//  main.cpp
//  211003-01
//
//  Created by 박경선 on 2021/10/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
void print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        cout << to_string(*(v_first + i)) + " ";
}

template<typename T> void print_queue(T q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> p (scoville.begin(), scoville.end());
    print_vector(scoville);
    while (p.size() > 1 && p.top() < K) {
        int f = p.top(); p.pop();
        f = f + (p.top() * 2);
        p.pop(); p.push(f);
        answer++;
    }
    
    if (p.size() < 2 && p.top() < K) return -1;
    return answer;
}

int main() {
    int result = solution({1, 9, 2, 3, 12, 10}, 15);
//    int result = solution({1, 2}, 15);
    
    cout << "\nresult : " << result << endl;

    return 1;
}
