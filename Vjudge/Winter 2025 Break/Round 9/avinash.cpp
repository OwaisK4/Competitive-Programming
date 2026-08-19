#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define int long long int
#define nl cout << endl;
#define PB push_back
#define MP make_pair
#define f(a, b) for (int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    vi a(n);
    map<int, vi> m;
    set<int> s;
    f(0, n) {
        cin >> a[i];
        m[a[i]].PB(i + 1);
        s.insert(a[i]);
    }
    int index = 0, value, c = 0, rem;
    for (auto it : s) {
        if (m[it].size() == 1)
            m.erase(it);
    }

    f(1, n + 1) {
        if (s.find(i) != s.end())
            continue;
        index = 0;
        value = 0;
        rem = -1;
        for (auto it : m) {
            c = 0;

            for (auto ind : it.second) {
                if (ind != i) {
                    index = ind;
                    // value = it.first;
                    break;
                }
                c++;
            }
            if (index) {
                m[it.first].erase(m[it.first].begin() + c);
                if (m[it.first].size() == 1)
                    rem = it.first;
                break;
            }
        }
        if (rem != -1)
            m.erase(rem);
        a[index - 1] = i;
    }
    cout << s.size() << endl;
    f(0, n) cout << a[i] << " ";

    nl
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}