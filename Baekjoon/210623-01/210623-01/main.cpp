#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'starsAndBars' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY startIndex
 *  3. INTEGER_ARRAY endIndex
 */

vector<int> starsAndBars(string s, vector<int> startIndex, vector<int> endIndex) {
    vector<int> result;
    for (int i =0; i< startIndex.size(); i++) {
        string str = s.substr(startIndex[i]-1, endIndex[i] - startIndex[i]);
        cout << "str : " << str << endl;
        str.erase(remove(str.begin(), str.end(), '|'), str.end());
        cout << "str : " << str << endl;
        result.push_back(str.size());
    }
    return result;
}


int main()
{

    string s;
    getline(cin, s);

    string startIndex_count_temp;
    getline(cin, startIndex_count_temp);

    int startIndex_count = stoi(startIndex_count_temp);

    vector<int> startIndex(startIndex_count);

    for (int i = 0; i < startIndex_count; i++) {
        string startIndex_item_temp;
        getline(cin, startIndex_item_temp);

        int startIndex_item = stoi(startIndex_item_temp);

        startIndex[i] = startIndex_item;
    }

    string endIndex_count_temp;
    getline(cin, endIndex_count_temp);

    int endIndex_count = stoi(endIndex_count_temp);

    vector<int> endIndex(endIndex_count);

    for (int i = 0; i < endIndex_count; i++) {
        string endIndex_item_temp;
        getline(cin, endIndex_item_temp);

        int endIndex_item = stoi(endIndex_item_temp);

        endIndex[i] = endIndex_item;
    }

    vector<int> result = starsAndBars(s, startIndex, endIndex);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }


    return 0;
}
