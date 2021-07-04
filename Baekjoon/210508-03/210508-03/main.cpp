#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> remove;
//    int pointer = k;
    
    for (int i =0; i< cmd.size(); i++) {
        if (cmd[i].size() > 1) {
            int cnt = cmd[i][2] - '0';
            
            if (
            
//            auto it = find(remove.begin(), remove.end(), k);
//            if (it != remove.end()) {
//                cout << "detact" << endl;
//                cnt++;
//            }
            if (cmd[i][0] == 'D') {
                cout << "down" << endl;
                k = (k-(cnt%n)) < 0 ? n + (k-(cnt%n)) : k-(cnt%n);
            } else {
                cout << "up" << endl;
                k = ((k+cnt)%n);
            }
        } else {
            if (cmd[i][0] == 'C') {
                remove.push_back(k);
            }
            else if (cmd[i][0] == 'Z') {
                remove.pop_back();
            }
        }
        
        cout << "cmd[i] : " << cmd[i] << endl;
        cout << "k : " << k << endl;
        cout << "remove : " << print_vector(remove) << endl;
        
    }
    
    for (int i =0; i < n; i++) {
        auto it = find(remove.begin(), remove.end(), i);
        
        if (it != remove.end()) answer += "X";
        else answer += "O";
    }
    
    return answer;
}

int main() {
    
    int n = 8;
    int k = 2;
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    string result = solution(n, k, cmd);
    
    
    
    cout << "result : " << result << endl;
    return 0;
}
