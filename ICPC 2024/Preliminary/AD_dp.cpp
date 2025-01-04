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
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    int index = -1;
    for (auto it : mp) {
        if (it.second % 2 != 0) {
            index = s.find(it.first, 0);
        }
    }
    print("Index = ", index);
    int cnt = 0;
    if (index != -1) {
        while (index < n / 2) {
            swap(s[index], s[index + 1]);
            index++;
            cnt++;
        }
        while (index > n / 2) {
            swap(s[index], s[index - 1]);
            index--;
            cnt++;
        }
    }

    function<int(int, int, string)> f = [&](int l, int r, string s) -> int {
        if (l >= r) {
            return 0LL;
        }
        int answer = INT_MAX;
        int left = s.find(s[r], l);
        int right = s.rfind(s[l], r);
        print(left, right);
        // return 0;
        string x = s, y = s;
        x.erase(s.begin());
        x.erase(s.begin() + right);
        answer = min(answer, f(l, r - 2, x) + (int)s.size() - right - 1LL);
        y.erase(s.end() - 1);
        y.erase(s.begin() + left);
        answer = min(answer, f(l, r - 2, y) + left);
        return answer;
    };
    print(s);
    int answer = f(0, s.size() - 1, s) + cnt;
    print(answer);
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