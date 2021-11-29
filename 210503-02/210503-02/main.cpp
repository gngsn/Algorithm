//
//  main.cpp
//  210503-02
//
//  Created by 박경선 on 2021/05/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> temp = numbers;
    vector<int> nums;
    for (int i = 0; i < numbers.size(); i++) {
        while (temp[i] / 10 > 10) temp[i] /= 10;
        nums.insert(numbers.begin(), numbers[i]);
    }
    
    sort(temp.begin(), temp.end(), greater<int>());
    cout << "answer : " << answer << endl;
    for (int t : temp) {
        answer += t;
    }
    cout << "answer : " << answer << endl;
    return answer;
}


int main() {
    vector<int> numbers = {3, 30, 34, 5, 9};
    string result = solution(numbers);
    
    cout << "result : " << result << endl;
    
    return 0;
}
