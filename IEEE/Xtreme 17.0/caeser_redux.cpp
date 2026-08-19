#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ld long double
#define nl cout << "\n";
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define forn(a, b) for (int i = a; i < b; i++)
#define __builtin_popcountll __builtin_popcountll
#define __builtin_clzll __builtin_clzll
#define __builtin_ctzll __builtin_ctzll
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define mod1 1000000007
#define mod2 998244353
void solve() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    // cin.ignore();
    int sz = s.length();
    // cout<<sz;nl;
    bool f = 0;
    if (s == "the") {
        f = 1;
    } else {

        forn(0, sz) {

            if (i + 4 < n && s.substr(i, 5) == " the ") {
                f = 1;
            }
            if (i == 0 && i + 3 < n && s.substr(i, 4) == "the ") {
                f = 1;
            }
            if (i + n == sz - 1 && s.substr(i, 4) == " the") {
                f = 1;
            }
        }
    }

    if (f) {
        forn(0, sz) {
            if (s[i] == ' ')
                continue;

            if (s[i] - n >= 'a') {
                s[i] -= n;
            } else {
                // cout << s[i] << " "
                // 	 << "here";nl;
                int x = n - (s[i] - 'a');
                s[i] = 'z';
                x--;
                s[i] -= x;
            }
        }
    } else {
        forn(0, sz) {
            if (s[i] == ' ')
                continue;
            if (s[i] + n <= 'z') {

                s[i] += n;
            } else {
                int x = n;
                x = n - ('z' - s[i]);
                s[i] = 'a';
                x--;
                s[i] += x;
            }
        }
    }
    cout << s;
}
signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        nl;
    }
    return 0;
}