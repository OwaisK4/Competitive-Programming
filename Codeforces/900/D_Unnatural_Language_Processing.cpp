#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

map<int, int> letters;

void solve() {
    int n;
    string s, answer;
    cin >> n >> s;
    for (int i = 0; i < n;) {
        answer += s[i];
        answer += s[i + 1];
        if (i + 2 == n - 1) {
            answer += s[i + 2];
            break;
        } else {
            if (i + 3 <= n - 1 && letters[s[i + 2]] == letters[s[i + 3]]) {
                answer += s[i + 2];
                if (i + 3 < n - 1)
                    answer += '.';
                i += 3;
            } else {
                if (i + 2 < n - 1)
                    answer += '.';
                i += 2;
            }
        }
    }
    cout << answer << "\n";
}

signed main() {
    fastio;
    for (auto c : {'a', 'e'}) {
        letters[c] = 'V';
    }
    for (auto c : {'b', 'c', 'd'}) {
        letters[c] = 'C';
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}