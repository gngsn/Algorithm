//
//  main.cpp
//  211024-02
//
//  Created by 박경선 on 2021/10/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <time.h>

using namespace std;

//map<string, bool> memo;
set<string> memo;

long back(string s, long c) {
    if (memo.find(s) != memo.end() || s.length() == 0) return 0;
    memo.emplace(s);
    
    if (s.length() == 1) return 1;
    
    return (1 + back(s.substr(0, s.length()-1), c) +
                back(s.substr(1, s.length()), c)) +
                back(s.substr(1, s.length()-1), c);
}

long substringCalculator(string s) {
    clock_t start, end;
    
    start = clock();
    long answer = back(s, 0);
    end = clock();
    double t = (double)(end - start);
    cout.precision(5);
    cout << "time : " << fixed << ((t) / CLOCKS_PER_SEC) << endl;
//    printf("%lf", d);
    return answer;
    
}

int main(int argc, const char * argv[]) {
    long result = substringCalculator("ghaqjdrmnegmrlrlfpjmnnngpwalzknsencuzwsnhfltwohdgbmvfuwtquosrnyerucntxxkfqehjqygcarxogvcfkljzbzutxphpyykapncjfclnhndzxghelyvzpylazhuutmcquusexzbhsfsmbnlvnlemzvfqbfzwquairhpylnbvyhiyamztlhfchhbwrqddmuzsprfdwuqqchcpeakkexackwwzihkfenwzwckynymgqydvjtovaoezkjjurylqcuonsujycziobnfnmuwnoxcdtahpituykvgpyyshvukrstcbmnsqtjseflwywnslmvnqrtnzkyaddkjamrezprqgoenzsdryygbkeahfiduozpwkrgmatszaxmwodsqiocvagbvxyqotpaujnqvqgjmfxnxhfbwqjpgodlxdrxpjpmzeabpgqrzpxomniknjkdiwtfgyvwvekrnoupwkcbtmpcfamzrghgrznuedkybmfwctdghcfawajlxfkzhdamuygjbcwnyglkjlfmpxfdtovkqbshhrfrnyjrgxgiozsuuncnwofkqzsypwgeikpfbhryhpszegdfajzvqlwwqlnvdtdiuckcvvosrdweohnmawqonjbxyjjhlccuteeshfrxxdhzgakwjqbymnaeudcmibsytyajsgdpfvrutcpglzxdevenevmkgalcrpknuvcrnkuboennhyzirfwvtozzijujsckbxqpocakzrbwgpqgjjmsrtwmvhwyraukbuxfvebeylfpipzwjdzlmgslbtwzataxgqpasrssnfwndldwkdutdqcmcpyanrbdsxrvcvpsywjambtbzlcrvzesuhvyvwwuwwdznigxjxknfajpknqutfvvqynkpvkzgypasevrpxofbymdzcitoqolwqegocuyqsexhumzmckzuuwkamolbltlifongpvkcnrnnuplftqbxpdnegdqlymftqyrxcnzmu");
    cout << "result : " << result;
    return 0;
}
