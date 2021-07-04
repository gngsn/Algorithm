#include <iostream>
#include <string>
#include <vector>
#define TBL_SIZE 5
using namespace std;


template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}

int abs (int a, int b) {
    return a > b ? a-b: b-a;
}

void print_pair (vector<pair<int, int>> v) {
    vector<pair<int, int>>::iterator iter;
   for(iter = v.begin(); iter != v.end(); iter++){
       cout << "[" << iter->first << "," << iter->second << "]" << endl;
   }
}

bool check_point(vector<string> places, vector<pair<int, int>> point) {
    for (int i = 0; i< point.size(); i++) {
        int x = point[i].first;
        int y = point[i].second;
        
        for (int j = i + 1; j< point.size(); j++) {
            
            if (abs(x, point[j].first) + abs(y, point[j].second) < 3) {
                if (x == point[j].first) {
                    if (places[x][(point[j].second + y)/2] != 'X')
                        return true;
                }
                else if (y == point[j].second){
                    if (places[(point[j].first+x)/2][y] != 'X')
                        return true;
                } else {
                    if (places[x][point[j].second] != 'X' && places[point[j].first][y] != 'X')
                        return true;
                }
            }
        }
    }
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<pair<int, int>> point;
    
    for (int round=0; round < places.size(); round++) {
        int ans = 1;
        for (int i =0; i <places[0].size(); i++) {
            for (int j =0; j<places[0].size(); j++) {
                if (places[round][i][j] == 'P') {
                    point.push_back(pair<int, int>(i, j));
                }
            }
        }
        if (check_point(places[round], point)) ans = 0;
        answer.push_back(ans);
        point.clear();
    }
    
    return answer;
}

int main() {
    vector<vector<string>> places =
    {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> result = solution(places);
    
    cout << "result : " << print_vector(result) << endl;
    return 0;
}
