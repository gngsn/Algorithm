#include <iostream>

using namespace std;

int main() {
    string crypto = "HCWYNIGYYNSIO";
    
    for (int n = 0; n < 26; n++) {
        string plain = "";
        for (char c: crypto) {
            c = c + n ;
            plain += c > 'Z' ? 'A' + (c-'Z'-1): c;
        }
        cout << "n이 " << n << "일 때, " << plain << endl;
    }
    return 0;
}
