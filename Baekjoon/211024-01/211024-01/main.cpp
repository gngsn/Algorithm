//
//  main.cpp
//  211024-01
//
//  Created by 박경선 on 2021/10/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Point {
public:
    int x;
    int y;
    int d;
    Point(int x, int y, int d) {
        this->x=x;
        this->y=y;
        this->d=d;
    }
};

int minMoves(int n, int startRow, int startCol, int endRow, int endCol) {
    int moves = INT_MAX;
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1};
    queue<Point> q;
    bool visit[n][n];
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            visit[i][j] = false;
    
    
    q.emplace(Point(startRow, startCol, 0));
    visit[startRow][startCol] = true;

    while(!q.empty()) {
        Point p = q.front();
        q.pop();
        cout << "\nx : " << p.x << ", y: " << p.y << ", dis: " << p.d << endl;
        
        if (p.x == endRow && p.y == endCol){
            cout << "Reach!" << endl;
            if(moves > p.d) moves = p.d;
        }
        
        for (int i=0; i<8; i++) {
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];
//            cout << "nx : " << nx << ", ny: " << ny << ", visit[nx][ny] : " << visit[nx][ny];
            if (nx>=0 && nx<n && ny>=0 && ny<n && !visit[nx][ny]) {
//                cout << ", pass";
                visit[nx][ny] = true;
                q.emplace(Point(nx, ny, p.d+1));
            }
//            cout << endl;
        }
    }
    
    return moves;
}


int main(int argc, const char * argv[]) {
    int result = minMoves(6, 5, 1, 0, 5);
    cout << "result : " << result;
    return 0;
}
