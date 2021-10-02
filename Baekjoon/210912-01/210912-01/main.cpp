//
//  main.cpp
//  210912-01
//
//  Created by 박경선 on 2021/09/12.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string poss(int l, vector<int> s, vector<int> e, string pos, int i, int j) {
    int c = j;
    while (c < l && e[i] > s[c]) c++;
    if (c < l) {
        pos += to_string(s[c])+to_string(e[c]);
        poss(l, s, e, pos, c, c+1);
    }
    return pos;
}

long paperCuttings(int textLength, vector<int> starting, vector<int> ending) {
    set<string> answer;
    for (int s = 0; s < starting.size(); s++) {
        for (int j = s; j < starting.size(); j++) {
            string pos = to_string(starting[s])+ to_string(ending[s]);
            if (ending[s] < starting[j]) {
                pos = poss(starting.size(), starting, ending, pos, s, j);
                answer.insert(pos);
            }
        }
    }
    for (auto i : answer) cout << i <<endl;
    return answer.size();
}

// 3, 1, 2, 8, 8
// 5, 3, 7, 10, 10


// 26, 49, 28, 10, 41, 83, 84,  1, 32, 20, 13, 74,  1,  3, 11,  5,  4, 74, 36, 14
// 96, 78, 99, 59, 75, 99, 91, 73, 39, 96, 35, 81, 92, 39, 36, 33, 97, 95, 76, 73

int main() {
//    vector<int> s = {3, 1, 2, 8, 8};
//    vector<int> f = {5, 3, 7, 10, 10};
//    int s[] = {1,1,6,7};
//    int f[] = {5,3,8,10};
//    int s[] = {1, 2, 4, 1, 5, 8, 9, 11, 13};
//    int f[] = {3, 5, 7, 8, 9, 10, 11, 14, 16};
    vector<int> s = {26, 49, 28, 10, 41, 83, 84, 1, 32, 20, 13, 74, 1, 3, 11, 5, 4, 74, 36, 14};
    vector<int> f = {96, 78, 99, 59, 75, 99, 91, 73, 39, 96, 35, 81, 92, 39, 36, 33, 97, 95, 76, 73};
    int n = sizeof(s)/sizeof(s[0]);
    long a = paperCuttings(n, s, f);
    cout << "answer : " << a << endl;
    return 0;
}
