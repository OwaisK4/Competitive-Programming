#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vi coins;
vi dp;

void fill_dp(){
    dp[0] = 0;
    for (int i=1; i<dp.size(); i++){
        for (auto it : coins){
            if (i - it >= 0 && dp[i - it] != LONG_LONG_MAX){
                dp[i] = min(dp[i], dp[i - it] + 1);
            }
        }
    }
}

signed main(){
    fastio;
    int n, x;
    cin >> n >> x;
    coins.assign(n, 0);
    dp.assign(x+1, LONG_LONG_MAX);
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    fill_dp();
    if (dp[x] != LONG_LONG_MAX)
        cout << dp[x];
    else
        cout << -1;
    return 0;
}