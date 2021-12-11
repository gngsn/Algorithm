//
//  main.cpp
//  211211-02
//
//  Created by 박경선 on 2021/12/11.
//

#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

string getBitstr(vector<string> pixels, int index) {
    string s = "";
    for (int j=0; j < 5; j++) s += pixels[j][index];
    return s;
}

string solution(vector<string> pixels) {
    string answer = "";
    vector<bitset<5>> bits;

    for (int i=0; i < pixels[0].size()-2; i+=3) {
        bitset<5> b(getBitstr(pixels, i));
        cout << "bit: " << b << endl;

        int n = b.to_ulong();
        if (n == 17) answer += '1';
        else if (n == 23) answer += '2';
        else if (n == 21) answer += '3';
        else if (n == 28) answer += '4';
        else if (n == 24) answer += '7';
        else {
            bitset<5> b2(getBitstr(pixels, i+2));
            n = b2.to_ulong();
            if (b.all()) {
                if (n == 23) answer += '6';
                else if (pixels[i+2][i+1] == '1') answer += '8';
                else answer += '0';
            } else {
                if (n == 23) answer += '5';
                else answer += '9';
            }
        }
    }

    return answer;
}
int main() {
    
//    bitset<5> b("10111");
//    cout << b.to_ulong() << endl;
    vector<string> s = {"111111111111111111111111110111111111","001101001101101100101101010101001100","111101111101101111101111010111111111","100101100101101101101001010101001001","111111111111111111111111111111111111"};
    string result = solution(s);
    cout << "\nresult : " << result << endl;

//    vector<int> result = solution(s, 15);
//    cout << "\nresult : ";
//        print_vector(result);
    return 1;
}
