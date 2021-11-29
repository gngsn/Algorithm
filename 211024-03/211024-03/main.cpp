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

typedef struct suffix {
    int idx;
    int rank[2];
} suffix;

int cmp(struct suffix a, struct suffix b) {
    return (a.rank[0] == b.rank[0]) ?
        (a.rank[1] < b.rank[1] ? 1: 0):(a.rank[0] < b.rank[0] ? 1: 0);
}

vector<int> makeSuffix(string s) {
    int n = s.size();
    suffix sf[n];
    int ind[n];
    vector<int> suffixArr;
    
    for (int i = 0; i < n; i++) {
        sf[i].idx = i;
        sf[i].rank[0] = s[i] - 'a';
        sf[i].rank[1] = ((i+1) < n) ? (s[i + 1] - 'a'): -1;
    }

    sort(sf, sf+n, cmp);
    
    for (int k=4; k < 2*n; k = k*2) {
        int rank = 0;
        int prev = sf[0].rank[0];
        sf[0].rank[0] = rank;
        ind[sf[0].idx] = 0;
        
        for (int i = 1; i < n; i++) {
            if (sf[i].rank[0] == prev && sf[i].rank[1] == sf[i-1].rank[1]) {
                prev = sf[i].rank[0];
                sf[i].rank[0] = rank;
            } else {
                prev = sf[i].rank[0];
                sf[i].rank[0] = ++rank;
            }
            ind[sf[i].idx] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int nextindex = sf[i].idx + k/2;
            sf[i].rank[1] = (nextindex < n)? sf[ind[nextindex]].rank[0]: -1;
        }
        sort(sf, sf+n, cmp);
    }

    for (int i = 0; i < n; i++) suffixArr.push_back(sf[i].idx);

    return suffixArr;
}

vector<int> lcp(string s, vector<int> suffixArr) {
    int n = suffixArr.size();
    int k = 0;
    vector<int> l(n, 0), inv(n, 0);
    
    for (int i=0; i < n; i++) inv[suffixArr[i]] = i;

    for (int i=0; i<n; i++) {
        if (inv[i] == n-1) {
            k = 0;
            continue;
        }

        int j = suffixArr[inv[i]+1];
        while (i+k<n && j+k<n && s[i+k]==s[j+k]) k++;

        l[inv[i]] = k;
        if (k>0) k--;
    }
    return l;
}

long substringCalculator(string s) {
    vector<int> suffixArr = makeSuffix(s);
    vector<int> l = lcp(s, suffixArr);
    long result = s.size() - suffixArr[0];

    for (int i = 1; i < l.size(); i++)
        result += (s.size() - suffixArr[i]) - l[i - 1];
        
    return result;
}

int main(int argc, const char * argv[]) {
    string s1 = "kincenvizh";
    string s2 = "ghaqjdrmnegmrlrlfpjmnnngpwalzknsencuzwsnhfltwohdgbmvfuwtquosrnyerucntxxkfqehjqygcarxogvcfkljzbzutxphpyykapncjfclnhndzxghelyvzpylazhuutmcquusexzbhsfsmbnlvnlemzvfqbfzwquairhpylnbvyhiyamztlhfchhbwrqddmuzsprfdwuqqchcpeakkexackwwzihkfenwzwckynymgqydvjtovaoezkjjurylqcuonsujycziobnfnmuwnoxcdtahpituykvgpyyshvukrstcbmnsqtjseflwywnslmvnqrtnzkyaddkjamrezprqgoenzsdryygbkeahfiduozpwkrgmatszaxmwodsqiocvagbvxyqotpaujnqvqgjmfxnxhfbwqjpgodlxdrxpjpmzeabpgqrzpxomniknjkdiwtfgyvwvekrnoupwkcbtmpcfamzrghgrznuedkybmfwctdghcfawajlxfkzhdamuygjbcwnyglkjlfmpxfdtovkqbshhrfrnyjrgxgiozsuuncnwofkqzsypwgeikpfbhryhpszegdfajzvqlwwqlnvdtdiuckcvvosrdweohnmawqonjbxyjjhlccuteeshfrxxdhzgakwjqbymnaeudcmibsytyajsgdpfvrutcpglzxdevenevmkgalcrpknuvcrnkuboennhyzirfwvtozzijujsckbxqpocakzrbwgpqgjjmsrtwmvhwyraukbuxfvebeylfpipzwjdzlmgslbtwzataxgqpasrssnfwndldwkdutdqcmcpyanrbdsxrvcvpsywjambtbzlcrvzesuhvyvwwuwwdznigxjxknfajpknqutfvvqynkpvkzgypasevrpxofbymdzcitoqolwqegocuyqsexhumzmckzuuwkamolbltlifongpvkcnrnnuplftqbxpdnegdqlymftqyrxcnzmu";
    int result = substringCalculator(s2);
    cout << "result : " << result << endl;
    return 0;
}
