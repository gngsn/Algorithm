//
//  main.cpp
//  210503-01
//
//  Created by 박경선 on 2021/05/03.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string print_vector (vector<int> v) {
    string str = "";
    int* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}

//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer;
//    for (int i = 0; i< commands.size(); i++) {
//        vector<int> sub;
//        sort(array.begin() + (commands[i][0]-1), array.end() - (commands[i][1]-1));
//        for (int j = commands[i][0]-1; j <= commands[i][1]-1; j++) {
//            int s = 0;
//            while (sub.size() != 0 && s < sub.size() && array[j] > sub[s]) s++;
//            sub.insert(sub.begin() + s, array[j]);
//        }
//        answer.push_back(sub[commands[i][2]-1]);
//    }
//    return answer;
//}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i< commands.size(); i++) {
        vector<int> sub = array;
//        cout << "before sub : " << print_vector(sub) << endl;
        sort(sub.begin() + (commands[i][0]-1), sub.begin() + (commands[i][1]));
//        cout << "after sub : " << print_vector(sub) << endl;
        answer.push_back(sub[commands[i][0]-1 + commands[i][2]-1]);
        
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    
    vector<int> result = solution(array, commands);
    cout << "result : " << print_vector(result) << endl;
    return 0;
}
