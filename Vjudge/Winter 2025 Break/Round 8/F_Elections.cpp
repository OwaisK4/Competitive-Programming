#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
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

double dist(int x1, int y1, int x2, int y2) {
    double mag = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return mag;
}

void solve() {
    int N;
    double D;
    cin >> N >> D;
    vii a(N, pii());
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<bool> infected(N, false);
    infected[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto i = q.front();
        q.pop();
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (dist(a[i].first, a[i].second, a[j].first, a[j].second) <= D && infected[j] == false) {
                infected[j] = true;
                q.push(j);
            }
        }
    }
    // if (dist(a[i].first, a[i].second, a[j].first, a[j].second) <= D && (infected[i] == true || infected[j] == true)) {
    //     infected[i] = true;
    //     infected[j] = true;
    // }
    for (int i = 0; i < N; i++) {
        if (infected[i]) {
            print("Yes");
        } else {
            print("No");
        }
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