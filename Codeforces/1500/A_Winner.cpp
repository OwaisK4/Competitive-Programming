#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
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
}
template <typename T>
void print(T X) {
    cout << X << " ";
}

void solve() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> scores(n);
    map<string, int> total;
    map<string, vector<pair<int, int>>> last;

    cin.ignore();
    for (int i = 0; i < n; i++) {
        string line, a, b;
        getline(cin, line);
        stringstream ss(line);
        ss >> a;
        ss >> b;
        names[i] = a;
        scores[i] = stoll(b);
        total[names[i]] += scores[i];
        last[names[i]].push_back({total[names[i]], i});
    }
    int maximum = numeric_limits<int>::min();
    for (auto &[name, score] : total) {
        maximum = max(maximum, score);
    }

    vector<string> winners;
    for (auto &[name, score] : total) {
        // cout << score << " ";
        if (score == maximum) {
            winners.push_back(name);
        }
    }
    if (winners.size() == 1) {
        cout << winners.back();
        return;
    }
    int fastest = INT_MAX;
    string winner;
    for (auto it : winners) {
        int k = -1;
        for (auto jt : last[it]) {
            if (jt.first >= maximum) {
                k = jt.second;
                break;
            }
        }
        if (k < fastest) {
            fastest = k;
            winner = it;
        }
    }
    cout << winner;
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