#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    map<int, int> mp;
    int n = 5;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            mp[i * j]++;
        }
    }
    int count = 0;
    for (auto it : mp){
        for (int i=0; i<it.second; i++){
            count++;
            cout << it.first << " ";
        }
    }
    cout <<"\nCount = " << count;

    long long int median = (n*n + 1) / 2.0;
    auto it = lower_bound(all(mp), median);

    return 0;
}