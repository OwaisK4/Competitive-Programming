#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
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
using namespace std;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    if (count(all(s), 'X') == 0) {
        cout << min(n, k);
        return;
    }
    string original = s;

    priority_queue<pii> pq;
    int start = 0, end;
    while (start < n && s[start] == 'X') {
        start++;
    }
    while ((end = s.find('X', start)) != s.npos) {
        int gap = end - start;
        pq.push({gap, start});
        start = end + 1;
        while (start < n && s[start] == 'X') {
            start++;
        }
    }
    int gap = n - start;
    if (gap)
        pq.push({gap, start});
    while (!pq.empty()) {
        auto [gap, index] = pq.top();
        pq.pop();
        if (k < gap) {
            break;
        }
        k -= gap;
        while (gap) {
            s[index] = 'X';
            index++;
            gap--;
        }
    }
    int maximum = 0;
    int cnt = 0;
    priority_queue<int> longest;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (cnt) {
                longest.push(cnt);
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt) {
        longest.push(cnt);
    }
    int X = longest.top();
    int answer = min(X + k, n);

    s = original;
    priority_queue<pii, vector<pii>, greater<pii>> qp;
    start = 0;
    while (start < n && s[start] == 'X') {
        start++;
    }
    while ((end = s.find('X', start)) != s.npos) {
        int gap = end - start;
        qp.push({gap, start});
        start = end + 1;
        while (start < n && s[start] == 'X') {
            start++;
        }
    }
    gap = n - start;
    if (gap)
        qp.push({gap, start});
    while (!qp.empty()) {
        auto [gap, index] = qp.top();
        qp.pop();
        if (k < gap) {
            break;
        }
        k -= gap;
        while (gap) {
            s[index] = 'X';
            index++;
            gap--;
        }
    }
    maximum = 0;
    cnt = 0;
    priority_queue<int> llongest;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (cnt) {
                llongest.push(cnt);
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt) {
        llongest.push(cnt);
    }
    X = llongest.top();
    int answer2 = min(X + k, n);

    cout << max(answer, answer2);
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