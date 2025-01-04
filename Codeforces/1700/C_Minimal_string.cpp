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

void solve() {
    string s, u;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    stack<char> st;
    set<char> sc;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        sc.insert(s[i]);
    }
    // for (auto it : sc) {
    //     cout << it << " ";
    // }
    // print("");
    char minimum = *sc.begin();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= minimum) {
            u += st.top();
            st.pop();
        }
        if (s[i] == minimum) {
            u += s[i];
            if (--mp[minimum] <= 0) {
                mp.erase(minimum);
                sc.erase(minimum);
                minimum = *sc.begin();
            }
        } else {
            st.push(s[i]);
            if (--mp[s[i]] <= 0) {
                mp.erase(s[i]);
                sc.erase(s[i]);
            }
        }
    }
    while (!st.empty()) {
        u += st.top();
        st.pop();
    }
    print(u);
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