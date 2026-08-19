#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void solve() {
    set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
    int n = 0, g = 0, y = 0, c = 0, v = 0;
    string s;
    cin >> s;
    int m = s.size();
    for (int i = 0; i < m; i++) {
        if (vowels.find(s[i]) != vowels.end())
            v++;
        else if (s[i] == 'Y') {
            y++;
        } else if (s[i] == 'N') {
            n++;
        } else if (s[i] == 'G') {
            g++;
        } else {
            c++;
        }
    }
    int answer = -INF;
    int length = -INF;

    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= min(n, g); j++) {
            int vows = v + i;
            int cons = c + (y - i) + j + (n - j) + (g - j);
            answer = max(answer, min(vows, cons / 2));
            if (vows <= cons / 2) {
                length = max(length, vows + (2 * vows) + min(2 * vows, j));
            } else {
                length = max(length, (cons / 2) + ((cons / 2) * 2) + min((cons / 2) * 2, j));
                // length = max(length, );
            }
        }
    }
    print(length);
    // print(answer);
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}