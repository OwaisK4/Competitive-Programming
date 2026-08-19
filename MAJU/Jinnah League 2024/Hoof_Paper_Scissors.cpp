#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define forn(i, a, n) for (int i = a; i < n; i++)
#define fornr(i, a, n) for (int i = n - 1; i >= a; i--)
#define print(a) cout << a << "\n";
#define printarr(a)                           \
    forn(i, 0, a.size()) cout << a[i] << " "; \
    cout << endl;
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define f first
#define s second
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sorted(a) is_sorted(all(a))
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define vpii vector<pair<int, int>>
#define MOD1 1000000007
#define mii map<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    vc a(n);
    forn(i, 0, n) cin >> a[i];
    vector<vvi> dp(n, vvi(3, vi(k + 1, -1)));
    // 0 for hoof, 1 for paper, 2 for scissors, so 1 beats 0, 2 beats 1, 0 beats 2
    function<long long(int, int, int)> f = [&](int index, int option, int count) -> long long {
        if (count > k) {
            return INT_MIN;
        }
        if (index == n) {
            return 0;
        }
        if (dp[index][option][count] != -1) {
            return dp[index][option][count];
        }

        int ans = 0;

        // if option we are on is opposite of ch, we can increment, otherwise we can either change or increment
        // or keep it same
        if (a[index] == 'H') {
            if (option == 1) {
                ans = max(ans, 1 + f(index + 1, option, count));
            } else {
                ans = max(ans, 1 + f(index + 1, 1, count + 1));
                ans = max(ans, f(index + 1, option, count));
            }
        } else if (a[index] == 'P') {
            if (option == 2) {
                ans = max(ans, 1 + f(index + 1, option, count));
            } else {
                ans = max(ans, 1 + f(index + 1, 2, count + 1));
                ans = max(ans, f(index + 1, option, count));
            }
        } else if (a[index] == 'S') {
            if (option == 0) {
                ans = max(ans, 1 + f(index + 1, option, count));
            } else {
                ans = max(ans, 1 + f(index + 1, 0, count + 1));
                ans = max(ans, f(index + 1, option, count));
            }
        }
        return dp[index][option][count] = ans;
    };
    int ans = max({f(0, 0, 0), f(0, 1, 0), f(0, 2, 0)});
    print(ans)
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    file_read("hps.in");
    file_write("hps.out");
    // cin >> t;
    while (t--) {
        solve();
    }
}