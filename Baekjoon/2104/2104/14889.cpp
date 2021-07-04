//
//  14889.cpp
//  2104
//
//  Created by 박경선 on 2021/04/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    
    int n, min = 2147483647;
    scanf("%d", &n);
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = ((1 << (n/2)) - 1); i < (1 << n); i++) {
        vector<int> start, link;
        int start_score = 0, link_score = 0;
        
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) start.push_back(j);
            else link.push_back(j);
        }
        
        if (start.size() != n/2) continue;
        
        for (int i = 0; i < start.size() - 1; i++) {
            for (int j = i + 1; j < link.size(); j++) {
                int sf = start[i];
                int ss = start[j];
                start_score += a[sf][ss] + a[ss][sf];
            }
        }
        for (int i = 0; i < link.size() - 1; i++) {
            for (int j = i + 1; j < link.size(); j++) {
                int lf = link[i];
                int ls = link[j];
                link_score += a[lf][ls] + a[ls][lf];
            }
        }
        int gap = start_score > link_score ? start_score - link_score : link_score - start_score;
        if (min > gap) min = gap;
    }
    cout << min << endl;
    return 0;
}
