//
//  main.cpp
//  210911-03
//
//  Created by 박경선 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Request {
private:
    int duration;
    int classify;
    int priority;
public:
    Request(int _duration, int _classify, int _priority)
            : duration(_duration), classify(_classify), priority(_priority) {}
    string to_string() {
        return "duration : " + ::to_string(duration) +
        ", classify ; " + ::to_string(classify) +
        ", priority ; " + ::to_string(priority);
    }
};
    
vector<int> solution(vector<vector<int>> jobs) {
    vector<int> answer;
    vector<Request> re;
    
    for (int i = 0; i < jobs.size();) {
        vector<int> job = jobs[i];
        int j = i+1;
        while(j < jobs.size() && jobs[i][2] == jobs[j][2]) {
            jobs[i][1] += jobs[j++][1];
            
        }
        
        Request r(jobs[i][1], jobs[i][2], jobs[i][3]);
        cout << r.to_string() << endl;
        i=j;
        re.push_back(r);
    }
    
    return answer;
}

template<typename T>
string print_vector (vector<T> v) {
    string str = "";
    T* v_first = &v[0];
    for (auto i = 0; i < v.size(); i++)
        str += to_string(*(v_first + i)) + " ";
    return str;
}

int main() {
    vector<int> result = solution({
        {1, 5, 2, 3},
        {2, 2, 3, 2},
        {3, 1, 3, 3},
        {5, 2, 1, 5},
        {7, 1, 1, 1},
        {9, 1, 1, 1},
        {10, 2, 2, 9}
    });
    cout << "result : " << print_vector(result) << endl;
    return 0;
}

