#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;
vector<bool> dp;

bool solve(int n, int m){
    if (dp[n]){
        return dp[n];
    }
    if (n == m){
        return true;
    }
    else if (n % 3 != 0){
        return false;
    }
    return dp[n] = solve(2 * n / 3, m) || solve(n / 3, m);
}

signed main(){
    int t;
    cin >> t;

    while (t--){
        int n, m;
        cin >> n >> m;

        dp.assign(n+1, 0);
        int answer = solve(n, m);
        if (answer <= 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}