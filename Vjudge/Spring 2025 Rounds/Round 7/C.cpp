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
    int n;
    cin >> n;
    string x;
    cin >> x;
    vi indexes;
    int i = n / 2;
    while (i >= 0 && x[i] == '0')
        i--;
    if (i >= 0) {
        indexes.push_back(i);
        i--;
    }
    while (i >= 0 && x[i] == '0')
        i--;
    if (i >= 0) {
        indexes.push_back(i);
    }

    i = n / 2 + 1;
    while (i < n && x[i] == '0')
        i++;
    if (i < n) {
        indexes.push_back(i);
        i++;
    }
    while (i < n && x[i] == '0')
        i++;
    if (i < n) {
        indexes.push_back(i);
    }
    // print(indexes);

    int sum = LINF;
    for (auto j : indexes) {
        string s1 = "", s2 = "";
        for (int i = 0; i <= j; i++) {
            s1 += x[i];
        }
        for (int i = j + 1; i < n; i++) {
            s2 += x[i];
        }
        int current = 0;
        for (int i = s1.size() - 1; i >= 0; i--) {
            current += (s1[i] - '0') * (pow(10, s1.size() - 1 - i));
        }
        for (int i = s2.size() - 1; i >= 0; i--) {
            current += (s2[i] - '0') * (pow(10, s2.size() - 1 - i));
        }
        sum = min(sum, current);
    }
    print(sum);
}

signed main() {
    fastio;
    print((int)pow(10, 50000));
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}