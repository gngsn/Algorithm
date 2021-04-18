//
//  43165.cpp
//  level1
//
//  Created by 박경선 on 2021/02/25.
//

#include "print.cpp"
#include <string>
#include <vector>

using namespace std;

class q43165 {
    int total = 0;
    void dfs(vector<int> numbers, int target, int sum, int count) {
        if (count >= numbers.size()) {
            if (sum == target) total++;
            return;
        }
        
        dfs(numbers, target, sum + numbers[count], count+1);
        dfs(numbers, target, sum - numbers[count], count+1);
    }
    
    int solution(vector<int> numbers, int target) {
        
        dfs(numbers, target, 0+numbers[0], 1);
        dfs(numbers, target, 0-numbers[0], 1);
        
        return total;
    }
    int main() {
        vector<int> numbers = {1, 1, 1, 1, 1};
        int target = 3;
        
        int answer = solution(numbers, target);
        cout << "answer : " << answer << endl;
        return 0;
    }
};
