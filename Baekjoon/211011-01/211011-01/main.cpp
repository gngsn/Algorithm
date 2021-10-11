//
//  main.cpp
//  211011-01
//
//  Created by 박경선 on 2021/10/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    size_t pos = 0;
    string answer ="(None)";
    int alen = 0;
    string info[4];
    
    for (int i=0; i<musicinfos.size(); i++) {
        for (int t=0; t<4; t++) {
            pos = musicinfos[i].find(",");
            info[t] = musicinfos[i].substr(0, pos);
            musicinfos[i].erase(0, pos+1);
        }
        
        int hour = stoi(info[1].substr(0,2))-stoi(info[0].substr(0,2));
        int min = stoi(info[1].substr(3,2))-stoi(info[0].substr(3,2));

        if (min < 0) {
            hour--;
            min+=60;
        }
        
        min += hour * 60;
        string melody = "";
        size_t n = info[3].size() - count(info[3].begin(), info[3].end(), '#');
        
        while (min>=n) {
            melody += info[3];
            min -= n;
        }
        
        for (int in=0; in<info[3].size(), min>0; in++, min--) {
            melody += info[3][in];
            if (info[3][in+1] == '#') {
                melody += "#";
                in++;
            }
        }
        
        int p = melody.find(m);
        while(p != string::npos) {
            if (melody[p+m.size()] != '#' && melody.size() > alen) {
                answer=info[2];
                alen=melody.size();
            }
            p = melody.find(m, p+m.size());
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    return 0;
}
