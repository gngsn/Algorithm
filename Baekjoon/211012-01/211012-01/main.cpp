//
//  main.cpp
//  211012-01
//
//  Created by 박경선 on 2021/10/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class File {
public:
    string head = "";
    int num;
    string tail = "";
    string raw = "";
};

bool comp (File f1, File f2) {
    if (f1.head < f2.head)
        return true;
    else if (f1.head > f2.head)
        return false;
    else
        return f1.num < f2.num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> vf;
    
    for (int i=0; i< files.size(); i++) {
        string tmp = "";
        string f = files[i];
        int idx = 0;
        File file;
        
        file.raw = f;
        while(!isdigit(f[idx])) tmp += tolower(f[idx++]);
        file.head = tmp;
        
        tmp = "";
        while(isdigit(f[idx])) tmp += f[idx++];
        file.num = stoi(tmp);
        file.tail = f.substr(idx, f.size());
        
        vf.push_back(file);
    }
    
    stable_sort(vf.begin(), vf.end(), comp);
    
    for (File ff : vf) cout << ff.raw << " "  << endl;

    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> result = solution({"img12.png", "abc10.png", "img02.png", "IMG01.GIF", "img1.png", "img2.JPG"});
//    vector<string> result = solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
    
    cout << "result : ";
    for (string r: result) cout << r << " ";
    return 0;
}
