#include <bits/stdc++.h>
#define int long long
#define file_write(filepath) freopen(filepath, "w", stdout);

using namespace std;
int mod = (int)1e9 + 7;

signed main() {
    file_write("/home/owaisk4/Win_backup/Speed Programming/CSES/output_array_description_gatta");
    int n, m;
    cin >> n >> m;
    int arr[n];
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= m; x++) {
            if (i == 1) {
                if (arr[i - 1] == 0 || arr[i - 1] == x)
                    dp[i][x] = 1;
                else
                    dp[i][x] = 0;
            } else {
                if (arr[i - 1] == 0 || arr[i - 1] == x)
                    dp[i][x] = dp[i - 1][x + 1] + dp[i - 1][x] + dp[i - 1][x - 1];
                else
                    dp[i][x] = 0;
            }
            dp[i][x] %= mod;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    for (int x = 1; x <= m; x++) {
        ans += (dp[n][x]) % mod;
        ans %= mod;
    }
    cout << ans;
}