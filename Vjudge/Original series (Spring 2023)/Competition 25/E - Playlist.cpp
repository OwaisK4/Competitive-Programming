#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> k(n);
    map<int, int> mp;
    for (int i=0; i<n; i++){
        cin >> k[i];
    }
    // mp[k[0]]++;
    int maximum = numeric_limits<int>::min();
    int i, j;
    for (i=0, j=0; i<n; i++){
        mp[k[i]]++;
        while (mp[k[i]] > 1){
            mp[k[j]]--;
            if (mp[k[j]] == 0){
                mp.erase(k[j]);
            }
            j++;
        }
        maximum = max(maximum, (int) mp.size());
        // maximum = max(maximum, i - j);
    }
    cout << maximum;
}

signed main(){
    solve();
    return 0;
}