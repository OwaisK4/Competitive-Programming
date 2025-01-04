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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<tuple<char, int>> st;
    for (int i = 0; i < n; i++) {
        if (st.size() && get<0>(st.top()) == s[i]) {
            auto [c, cnt] = st.top();
            st.pop();
            st.push(make_tuple(s[i], cnt + 1));
        } else if (!st.size() || (st.size() && get<0>(st.top()) != s[i])) {
            st.push(make_tuple(s[i], 1));
        }
        while (st.size() && get<1>(st.top()) >= k) {
            auto [c, cnt] = st.top();
            st.pop();
            if (cnt - k > 0)
                st.push(make_tuple(s[i], cnt - k));
        }
    }
    string answer = "";
    while (st.size()) {
        auto [c, cnt] = st.top();
        st.pop();
        answer += string(cnt, c);
        // print("Here");
    }
    reverse(all(answer));
    cout << answer;
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