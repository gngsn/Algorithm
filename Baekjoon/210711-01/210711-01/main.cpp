//
//  main.cpp
//  210711-01
//
//  Created by 박경선 on 2021/07/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool bfs(vector<string> p, int x, int y, int i, int j) {
    if (x+i == p[y].size() || y+j == p.size()) return false;
    if (abs(x-i) + abs(y-j) > 2) return false;
    cout << "\n\nx : " << x << ", y : " << y << endl;
    cout << "x+i : " << (x+i) << ", y+j : " << (y+j) << endl;
    if (p[y+j].at(x+i) == 'P') {
        if (i == 0 || j == 0) {
            if (i+j > 1)
            if (p[((y+j)/2)].at((x+i)/2) == 'X') return false;
        }
        if (p[y].at(x+i) == 'X' && p[y+j].at(x) == 'X') return false;
        cout << "p[y].at(x+i) : " << p[y].at(x+i) << endl;
        cout << "p[y+j].at(x) : " << p[y+j].at(x) << endl;
        cout << "\nmatch!" << endl;
        return true;
    }
    
    bfs(p, x, y, i+1, j);
    bfs(p, x, y, i, j+1);
    
    return false;
}

template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
//    for (vector<string> p : places) {
        int r = 1;
    vector<string> p = places[2];
    for (int y = 0; y < p.size(); y++) {
        for (int x = 0; x < p[y].size(); x++) {
            if (p[x].at(y) != 'P') continue;
            if (bfs(p, x, y, 1, 0) || bfs(p, x, y, 0, 1)) {
                r = 0;
                break;
            }
            if (r != 1) break;
        }
        if (r != 1) break;
    }
//        answer.push_back(r);
//    }
//    cout << "\nanswer : " << print_vector(answer);
    
    return answer;
}

int main() {
    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    
//    solution(places);
    return 0;
}
