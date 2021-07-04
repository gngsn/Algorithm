
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printMaxActivities(int s[], int f[], int n)
{
    int i = 0, j;
    cout <<" "<< i;

    for (j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            cout <<" " << j;
            i = j;
        }
    }
}

int solution(vector<vector<int>> ads) {
    int answer = 0;
    int start = ads[0][0];
    int time = 0;
    int a =0;
    
    
    for (int i = 0; i< ads.size() ; i++) {
        int delay = ads[i][0];
        int price = ads[i][1];
//        time += delay;
        if (i != 0) {
            cout << "delay : " << delay << endl;
            cout << "time : " << time << endl;
            a += ((time - delay) * price);
            cout << "a : " << a << endl;
        }
        time = start + time + 5;
        cout << "i : " << i << endl;
    }
    
    
    
    
    return answer;
}

int main()
{
//    int s[] = {1, 3, 0, 5, 8, 5};
//    int f[] = {2, 4, 6, 7, 9, 9};
    vector<vector<int>> ads = {{1, 3}, {3, 2}, {5, 4}};
//    int n = sizeof(s)/sizeof(s[0]);
//    printMaxActivities(s, f, n);
    solution(ads);
    return 0;
}
