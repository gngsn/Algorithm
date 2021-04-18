#include <iostream>
#include<string>
#include<sstream>
#include <vector>

using namespace std;


string print_vector (vector<char> v) {
    string str = "";
    for (char c : v ) {
        str += c + " ";
    }
    return str;
}

string print_vector_string (vector<string> v) {
    string str = "";
    string* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += *(v_first + i) + " ";
    return str;
}

vector<string> dfs (vector<vector<string>> skills, vector<string> str, string start, string s, int index) {
    for ( int i =0; i < skills.size(); i++) {
        bool next = false;
        if (skills[i][0] == start) {
            next = true;
            str = dfs(skills, str, skills[i][1], s + ' ' + skills[i][1], i);
        }
        
        vector<string>::iterator it = find(str.begin(), str.end(), s);
        if (it == str.end() && s.size() > 1 && (index !=0 && !next)) str.push_back(s);
    }
    return str;
}

int main() {
    string skill_str;
    vector<string> skills;
    string buffer;
    int k;
    
    getline(cin, skill_str);
    istringstream ss(skill_str);
    while (getline(ss, buffer, ' ')) skills.push_back(buffer);
    cin >> k;
    
    vector<vector<string>> arr;
    while (k--) {
        string sk1;
        string sk2;
        vector<string> values;
        cin>> sk1 >> sk2;
        
        values.push_back(sk1);
        values.push_back(sk2);
        arr.push_back(values);
    }
    
    string start = arr[0].front();
    string s = start;
    
    vector<string> str;
    str = dfs(arr, str, start, s, 0);
    
    for(auto it = str.begin(); it != str.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}



//h g f w r
//4
