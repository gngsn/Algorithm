//
//  main.cpp
//  211208-01
//
//  Created by 박경선 on 2021/12/08.
//

#include <iostream>
#include <vector>
typedef unsigned long ul;
using namespace std;

int MOD = 20170805;

void print(vector<vector<int>> v) {
    for (int y=0; y < v.size(); y++) {
        for (int x=0; x < v[0].size(); x++) {
            cout << v[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solution(int m, int n, vector<vector<int>> city_map) {
//    vector<vector<int>> pos(m+1, vector<int>(n+1, 0));
    vector<vector<vector<ul>>> pos(m+1, vector<vector<ul>>(n+1, vector<ul>(2)));
//    cout << "city map" << endl;
//    print(city_map);
//    cout << endl;
    pos[1][1][0] = pos[1][1][1] = 1;
    
    for (int y=1; y <= m; y++) {
        for (int x=1; x <= n; x++) {
            if (city_map[y-1][x-1] == 0) {
                pos[y][x][0] += pos[y-1][x][0] + pos[y][x-1][1];
                pos[y][x][1] += pos[y-1][x][0] + pos[y][x-1][1];
            } else if (city_map[y-1][x-1] == 1) pos[y][x][0] = pos[y][x][1] = 0;
            else {
                pos[y][x][0] = pos[y-1][x][0];
                pos[y][x][1] = pos[y][x-1][1];
            }
        }
    }
    
    for (int y=0; y <= m; y++) {
        for (int x=0; x <= n; x++) {
            cout << pos[y][x][0] << " ";
        }
        cout << endl;
    }
//    cout << "position" << endl;
//    print(pos);
//    cout << endl;
    
    
    return pos[m][n][0] % MOD;
}


int main() {
//        vector<vector<int>> s = {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};
//    vector<vector<int>> s = {{0, 2, 0, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0, 0}, {1, 0, 0, 2, 2, 2, 0}};
//    vector<vector<int>> s = {{0, 0, 0, 2, 0, 0}, {0, 0, 0, 2, 2, 0}, {0, 0, 1, 2, 1, 0}, {0, 0, 0, 0, 0, 0}};
//    vector<vector<int>> s = {{0, 1, 2, 1, 0}, {0, 2, 1, 2, 0}, {0, 1, 2, 1, 0}, {0, 0, 0, 0, 0}};
        vector<vector<int>> s = {{0, 0, 0, 2, 2, 0}, {0, 0, 1, 2, 1, 2}, {0, 0, 0, 2, 0, 0}, {0, 2, 2, 2, 2, 0}};
//        vector<vector<int>> s = {{2},{2},{2},{2}};
    int result = solution(s.size(), s[0].size(), s);
    cout << "\nresult : " << result << endl;

    return 1;
}
