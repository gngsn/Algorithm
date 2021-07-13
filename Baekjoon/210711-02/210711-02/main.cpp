//
//  main.cpp
//  210711-02
//
//  Created by 박경선 on 2021/07/11.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string print_vector (vector<string> v) {
    string str = "";
    string* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += *(v_first + i) + " ";
    return str;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;
    
    for (string r : record) {
        stringstream ss(r);
        string s, uid, nickname;
        getline(ss, s, ' ');
        getline(ss, uid, ' ');
        if (s == "Leave") continue;
        getline(ss, nickname, ' ');
        user[uid] = nickname;
    }
    
    for (string r : record) {
        stringstream ss(r);
        string s, uid;
        getline(ss, s, ' ');
        if (s == "Change") continue;
        getline(ss, uid, ' ');
        string a = user[uid] + "님이 " + (s == "Enter" ? "들어왔습니다." : "나갔습니다.");
        answer.push_back(a);
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    
    vector<string> answer = solution(record);
    cout << "answer : " << print_vector(answer) << endl;
    return 0;
}

