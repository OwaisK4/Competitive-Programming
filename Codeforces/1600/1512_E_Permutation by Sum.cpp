#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ld long double
#define nl cout << "\n";
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define forn(a, b) for (int i = a; i < b; i++)
#define __builtin_popcountll __builtin_popcountll
#define __builtin_clzll __builtin_clzll
#define __builtin_ctzll __builtin_ctzll
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define mod1 1000000007
#define mod2 998244353
int n, l, r, s;
int subarray_size;
bool flag = false;
vector<int> answer;
vector<int> last_answer;

void recur(int i, int sum, int cur_size) {
    if (flag) {
        return;
    }
    if (sum < 0) {
        answer.pop_back();
        return;
    }
    if (cur_size == subarray_size) {
        if (sum == 0) {
            last_answer = answer;
            flag = true;
        } else {
            answer.pop_back();
        }
        return;
    }
    // for (int j = i + 1; j <= n; j++) {
    //     answer.push_back(j);
    //     recur(j, sum - j, cur_size + 1);
    //     if (flag) {
    //         return;
    //     }
    // }
    for (int j = i - 1; j > 0; j--) {
        answer.push_back(j);
        recur(j, sum - j, cur_size + 1);
        if (flag) {
            return;
        }
    }
    answer.pop_back();
    return;
}

void solve() {
    cin >> n >> l >> r >> s;
    subarray_size = r - l + 1;
    // recur(0, s, 0);
    recur(n + 1, s, 0);
    if (!flag) {
        cout << -1 << "\n";
        answer.clear();
        last_answer.clear();
        flag = false;
        return;
    }
    set<int> s;
    for (auto it : last_answer) {
        // cout << it << " ";
        s.insert(it);
    }
    // cout << "\n";

    answer.assign(n, -1);
    for (int i = l; i <= r; i++) {
        answer[i - 1] = last_answer[i - l];
    }

    int counter = 1;
    int k = 0;
    while (counter <= n) {
        if (s.count(counter) == 0) {
            while (answer[k] != -1) {
                k++;
            }
            answer[k] = counter;
            counter++;
            k++;
        } else {
            counter++;
        }
    }

    for (auto it : answer) {
        cout << it << " ";
    }
    cout << "\n";
    answer.clear();
    last_answer.clear();
    flag = false;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}