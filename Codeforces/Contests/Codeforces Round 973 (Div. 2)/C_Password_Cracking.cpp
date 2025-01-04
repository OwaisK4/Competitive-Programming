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
    int n;
    cin >> n;
    int cnt = 0, response;
    string t = "";
    bool left = false;
    char zero = '0', one = '1';
    while (cnt < 2 * n) {
        cout << "? " << t + zero << endl;
        cin >> response;
        if (response == 1) {
            t += zero;
            if (t.size() == n)
                break;
            cnt++;
            continue;
        }
        cout << "? " << t + one << endl;
        cin >> response;
        if (response == 1) {
            t += one;
            if (t.size() == n)
                break;
            cnt++;
            continue;
        }
        left = true;
        break;
    }
    if (cnt < 2 * n && left) {
        if (t[0] == zero) {
            swap(zero, one);
        }
    }
    while (cnt < 2 * n && left) {

        cout << "? " << zero + t << endl;
        cin >> response;
        if (response == 1) {
            t = zero + t;
            if (t.size() == n)
                break;
            cnt++;
            continue;
        }
        cout << "? " << one + t << endl;
        cin >> response;
        if (response == 1) {
            t = one + t;
            if (t.size() == n)
                break;
            cnt++;
            continue;
        }
        left = true;
        break;
    }
    cout << "! " << t << endl;
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