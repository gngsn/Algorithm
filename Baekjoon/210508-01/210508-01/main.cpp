#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> numEng = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i =0; i < s.size(); i++) {
        int num = s[i]-'0';
        string en = "";
        while (i < s.size() && !(s[i] >= '0' && s[i] <= '9')) {
            en += s.at(i++);
            
            auto it = find(numEng.begin(), numEng.end(), en);
            if (it != numEng.end()) {
                num = it - numEng.begin();
                i--;
                break;
            }
        }
        answer = answer * 10 + num;
    }
    return answer;
}

int main() {
    string ss = "one4seveneight";
    int result = solution(ss);
    cout << "result : " << result << endl;
    return 0;
}
