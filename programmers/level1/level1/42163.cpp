//
//  43162.cpp
//  level1
//
//  Created by 박경선 on 2021/02/25.
//
#include "print.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class p43163 {
    bool check_one_str(string base, string comp) {
    bool check = false;
    for (int i = 0; i < base.size(); i++)
        if (base[i] != comp[i]) {
            if (check) return false;
            check = true;
        }
    return check && true;
}

void dfs(string begin, string target, vector<string> words, int index, vector<bool> &visited, int &min, int count) {
    if (index >= words.size() || visited[index]) return;
    visited[index] = true;
//    cout << "     words[index] : " << words[index] << endl;
    if (words[index] == target) {
        cout << " same! " << endl;
        min = count+1;
        cout << " min :  " << min << endl;
        return;
    }
    
    for (string word: words) {
        if (word != words[index] && check_one_str(words[index], word)) {
//            visited[index] = true;
            cout << " words[index] : "<< words[index] << endl;
            cout << " word : " << word << endl;
            cout << " check_one_str(words[index], word) : "<< check_one_str(words[index], word) << endl;
            dfs(begin, target, words, index+1, visited, min, count+1);
        }
        cout << endl;
    }
}

int solution(string begin, string target, vector<string> words) {
    int min = words.size() + 1;
    for (int i=0; i< words.size(); i++) {
        vector<bool> visited(words.size(), false);
        cout << "\n\nwords[i] : " << words[i] << endl;
        if (check_one_str(begin, words[i]))
            dfs(begin, target, words, i, visited, min, 1);
    }
    
    cout << "min : " << min << endl;
    
    return min > words.size() ? 0 : min;
}

int main() {
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> words2 = {"hot", "dot", "dog", "lot", "hig"};
    int answer = solution("hit", "cog", words);
    cout << "answer : " << answer << endl;
    return 0;
}
};
