//
//  main.cpp
//  211204-03
//
//  Created by 박경선 on 2021/12/04.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

template<typename T>
void print_vector (vector<T> vec) {
    string str = "";
    T* v_first = &vec[0];
    for (T v: vec) cout << to_string(v) + " ";
    cout << endl;
}

map<char, pair<int, int>> keyboard;
vector<vector<char>> ch = {
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o'},
    {'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k'},
    {'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'}
};


int getDistance(char a, char b) {
    return abs(keyboard[a].first - keyboard[b].first) +
        abs(keyboard[a].second - keyboard[b].second);
}

int solution(string s) {
    int answer = 0;
    map<string, int> memo;
    
    for (int i=0; i < ch.size(); i++)
        for (int j=0; j < ch[i].size(); j++)
            keyboard[ch[i][j]] = {i, j};
    
    for (int len = 1; len <= s.size(); len++) {
        for (int i = 0; i+len <= s.size(); i++) {
            string data = s.substr(i, len);
            cout << "\ndata : " << data << endl;
            if (len == 1) memo[data] = 0;
            else {
                int sum = memo[data.substr(0, data.size()-1)] +
                            getDistance(data[data.size()-2], data[data.size()-1]);
                memo[data] = sum;
                answer += sum;
                cout << "sum : " << sum << endl;
            }
        }
    }

    return answer;
}


int main() {
    string s = "toothabcctoothabcctoothabcctoothabcc";
    string s2 = "abcc";
    clock_t begin = clock();
    int result = solution(s);
    clock_t end = clock();
    cout << "Time difference = " << (double)(end - begin) << "[ms]" << endl;
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
