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
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

void solve() {
    map<string, vector<pair<string, int>>> debts;
    debts["Gabe"].push_back({"Bob", 30});
    debts["Gabe"].push_back({"David", 10});
    debts["Fred"].push_back({"Bob", 10});
    debts["Fred"].push_back({"Charlie", 30});
    debts["Fred"].push_back({"David", 10});
    debts["Fred"].push_back({"Ema", 10});
    debts["Bob"].push_back({"Charlie", 40});
    debts["Charlie"].push_back({"David", 20});
    debts["David"].push_back({"Ema", 50});
    // debts["A"].push_back({"B", 20});
    // debts["B"].push_back({"C", 20});

    queue<string> q;

    for (auto &[k, v] : debts) {
        sort(all(v), [](pair<string, int> a, pair<string, int> b) { return a < b; });
        q.push(k);
    }

    while (!q.empty()) {
        auto src = q.front();
        q.pop();
        if (debts[src].empty())
            continue;
        auto [interim, cost1] = debts[src].back();
        if (debts[interim].empty())
            continue;
        auto [dest, cost2] = debts[interim].back();
        debts[src].erase(debts[src].end() - 1);
        debts[interim].erase(debts[interim].end() - 1);
        int transitive = min(cost1, cost2);
        debts[src].push_back({dest, transitive});
        q.push(src);
        if (cost1 > cost2) {
            debts[src].push_back({interim, cost1 - transitive});
            q.push(interim);
            q.push(dest);
        }
        if (cost1 < cost2) {
            debts[interim].push_back({dest, cost2 - transitive});
            q.push(interim);
            q.push(dest);
        }
    }
    for (auto [src, dests] : debts) {
        for (auto [dest, cost] : dests) {
            cout << src << " owes " << cost << " to " << dest << "\n";
        }
    }
    // print("Here");
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