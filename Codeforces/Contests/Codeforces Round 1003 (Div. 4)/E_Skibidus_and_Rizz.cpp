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
    int n, m, k;
    cin >> n >> m >> k;
    // priority_queue<pii, vii, greater<pii>> pq;
    // pq.push({n, 0});
    // pq.push({m, 1});
    vi cnts = {n, m};
    vi a;
    int last = max_element(all(cnts)) - cnts.begin(), cnt = 1;
    a.push_back(last);
    cnts[last]--;
    // print(last);

    while (a.size() < n + m) {
        if (cnts[0] >= 0 && cnts[0] >= cnts[1]) {
            if (last == 0 && cnt < k) {
                cnt++;
                cnts[0]--;
                a.push_back(0);
            } else {
                if (cnts[1] == 0) {
                    print(-1);
                    return;
                }
                cnt = 1;
                last = 1;
                cnts[1]--;
                a.push_back(1);
            }
        } else if (cnts[1] >= 0 && cnts[1] >= cnts[0]) {
            if (last == 1 && cnt < k) {
                cnt++;
                cnts[1]--;
                a.push_back(1);
            } else {
                if (cnts[0] == 0) {
                    print(-1);
                    return;
                }
                cnt = 1;
                last = 0;
                cnts[0]--;
                a.push_back(0);
            }
        } else {
            print(-1);
            return;
        }
    }
    print(a);
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}