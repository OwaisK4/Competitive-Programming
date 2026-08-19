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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

void solve() {
    int n;
    cin >> n;
    // vector<int> prefix(202, 0);
    vector<pii> dist(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dist[i].first = a;
        dist[i].second = b;
    }
    if (n == 0) {
        cout << -100 << " " << -100;
        return;
    }
    bool found = false;
    int answer = -1;
    for (int i = -100; i <= 100; i++) {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            if (dist[k].first <= i && i <= dist[k].second) {
                cnt++;
            }
        }
        if (cnt == n) {
            answer = i;
            found = true;
        }
    }
    if (found == true) {
        cout << answer;
        return;
    }
    int answer_i = -1, answer_j = -1;
    for (int i = -100; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            int cnt_i = 0, cnt_j = 0;
            for (int k = 0; k < n; k++) {
                if (dist[k].first <= i && i <= dist[k].second) {
                    cnt_i++;
                } else if (dist[k].first <= j && j <= dist[k].second) {
                    cnt_j++;
                }
            }
            if (cnt_i + cnt_j == n) {
                answer_i = i;
                answer_j = j;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (answer_i == -1 && answer_j == -1) {
        cout << -1;
    } else {
        cout << answer_i << " " << answer_j;
    }
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