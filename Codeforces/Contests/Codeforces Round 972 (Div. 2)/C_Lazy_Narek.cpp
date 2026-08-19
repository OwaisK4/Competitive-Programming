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

int n, m;
vector<string> strings;
vector<vector<int>> dp;
set<char> narek = {'n', 'a', 'r', 'e', 'k'};
map<char, char> next_char = {{'n', 'a'}, {'a', 'r'}, {'r', 'e'}, {'e', 'k'}, {'k', 'n'}};

int f(int index, string current) {
    if (index == n) {
        return -current.size();
    }
    if (dp[index][current.size()] != -1) {
        return dp[index][current.size()];
    }
    string old_current = current;
    int score_n = 0;
    int score_c = 0;
    for (int i = 0; i < m; i++) {
        if (narek.find(strings[index][i]) != narek.end()) {
            if (current.empty() && strings[index][i] == 'n') {
                current.push_back('n');
            } else if (current.size() == 4 && strings[index][i] == 'k') {
                current.push_back('k'); // Just for show
                current = "";
                score_n += 5;
            } else if (current.size() && next_char[current.back()] == strings[index][i]) {
                current.push_back(strings[index][i]);
            } else {
                score_c++;
            }
        }
    }
    int answer = score_n - score_c;
    return dp[index][current.size()] = max(answer + f(index + 1, current), f(index + 1, old_current));
}

void solve() {
    cin >> n >> m;
    strings.assign(n, "");
    dp.assign(n, vector<int>(5, -1));
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    int answer = f(0, "");
    cout << answer << "\n";
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