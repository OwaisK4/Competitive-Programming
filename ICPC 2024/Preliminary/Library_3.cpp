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
void print(T X) {
    cout << X << "\n";
}
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void solve() {
    vector<int> S(3), F(3), H(3);
    int n = 3;
    for (int i = 0; i < n; i++) {
        cin >> S[i] >> F[i] >> H[i];
    }
    int answer = INT_MAX;
    string result;
    int value = S[1] + S[2] + F[0] + F[2] + H[0] + H[1];
    if (value < answer) {
        answer = value;
        result = "SFH";
    }

    value = S[1] + S[2] + F[0] + F[1] + H[0] + H[2];
    if (value < answer) {
        answer = value;
        result = "SHF";
    }

    value = S[0] + S[2] + F[0] + F[1] + H[1] + H[2];
    if (value < answer) {
        answer = value;
        result = "FHS";
    }

    value = S[0] + S[1] + F[0] + F[2] + H[1] + H[2];
    if (value < answer) {
        answer = value;
        result = "HFS";
    }

    value = S[0] + S[2] + F[1] + F[2] + H[0] + H[1];
    if (value < answer) {
        answer = value;
        result = "FSH";
    }

    value = S[0] + S[1] + F[1] + F[2] + H[0] + H[2];
    if (value < answer) {
        answer = value;
        result = "SHF";
    }
    print(result, answer);
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