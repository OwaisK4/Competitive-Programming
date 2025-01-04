#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vi coins;
vi dp;

int minimal(int sum){
    if (sum == 0){
        return dp[sum]=0;
    }
    if (dp[sum]!=-1)
        return dp[sum];
    if (sum < 0){
        return LONG_LONG_MAX - 1;
    }
    int answer = LONG_LONG_MAX;
    for (auto it : coins){
        answer = min(answer, minimal(sum - it) + 1);
    }
    return dp[sum]=answer;
}

signed main(){
    fastio;
    int n, x;
    cin >> n >> x;
    coins.assign(n, 0);
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    dp.assign(x+1,-1);
    cout << minimal(x) << "\n";
    return 0;
}