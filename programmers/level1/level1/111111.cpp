//
//  111111.cpp
//  level1
//
//  Created by 박경선 on 2021/02/27.
//

#include "print.cpp"
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class q11111{
string print_vector (vector<string> v) {
    string str = "";
    string* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += *(v_first + i) + " ";
    return str;
}

map<string, vector<string>> make_adj (vector<vector<string>> array) {
    map<string, vector<string>> adj;
    for (vector<string> arr : array) {
        vector<string> value = adj[arr[0]];
        
//        value.push_back(arr[1]);
        for (int i = 0; i < value.size(); i++) {
            if (arr[1].compare(value[i]) > 0) {
                value.insert(value.begin() + i, arr[1]);
                break;
            }
            if (i == (value.size()-1)) {
                value.push_back(arr[1]);
                break;
            }
        }
        if (value.empty()) value.push_back(arr[1]);
        adj[arr[0]] = value;
    }
    return adj;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<string>> adj = make_adj(tickets);
    answer.push_back("ICN");
    
    for (auto j = adj.begin(); j != adj.end(); j++) {
        cout << "\nkey : " << j -> first << endl;
        cout << "value : " << print_vector(j -> second) << endl;
    }
    
    for(int i = 0; i < tickets.size(); i++) {
        string tmp = answer.back();
        map<string, vector<string>>::iterator iter = adj.find(tmp);
        vector<string> values = iter -> second;
        answer.push_back(values.back());
        values.pop_back();
        adj[tmp] = values;
    }
    
    return answer;
}

int main() {
    vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}, {"IAD", "HND"}, {"HND", "IAD"}};
    vector<vector<string>> tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    vector<vector<string>> tickets3 = {{"ICN", "JFK"}, {"JFK", "ICN"}, {"ICN", "JFK"}, {"JFK", "ICN"}, {"ICN", "JFK"}};
//    {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}
//    {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}}
//    {{"ICN", "A"}, {"ICN", "B"}, {"B", "ICN"}}
    vector<vector<string>> tickets5 = {{"ICN", "A"}, {"ICN", "A"}, {"A", "ICN"}};
//    vector<vector<string>> tickets5 = {{"ICN", "A"}, {"A", "D"}, {"D", "B"}, {"B", "A"}};
//    {{"ICN", "B"}, {"ICN", "B"}, {"A", "B"}}
    vector<string> answer = solution(tickets2);
    cout << "\n\n\n answer : " << print_vector(answer) << endl;
    return 0;
}
};
