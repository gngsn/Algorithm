//
//  main.cpp
//  211204-02
//
//  Created by 박경선 on 2021/12/04.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
//vector<bool> suc;
bool start(vector<string> drum, int start) {
    int x = start, y = 0;
    bool flag = true;

    do {
        drum[y][x] = start;
        cout << "y : " << y << ", x : " << x << ", flag : " << flag << endl;
        if (drum[y][x] == '#') y++;
        else if (drum[y][x] == '>') x++;
        else if (drum[y][x] == '<') x--;
        else if (drum[y][x] == '*') {
            if (flag) {
                flag = false;
                y++;
            }
            else return false;
        } else
    } while (y != drum.size());

    cout << "true" << endl;
    return true;
}

int solution(vector<string> drum) {
    int answer = 0;
    
    for (int i = 0; i < drum.size(); i++) {
        if (start(drum, i)) {
            answer++;
//            success
        }
        
        cout << endl;
    }
    
    return answer;
}

int main() {
    vector<string> s = {"######",">#*###","####*#","#<#>>#",">#*#*<","######"};
    int result = solution(s);
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
