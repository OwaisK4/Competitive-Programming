#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        set<int> s;
        for (int i = 1; i <= p; i++) {
            s.insert(i);
        }
        int count = p;
        auto it = s.begin();
        int skip = 0;
        int k = 0;
        while (count > 1) {
            if (skip == k) {
                if (it == s.end()) {
                    auto to_erase = s.begin();
                    it = next(s.begin());
                    s.erase(to_erase);
                    count--;
                    skip++;
                    k = 0;
                } else {
                    auto to_erase = it;
                    it = next(it);
                    if (it == s.end()) {
                        it = s.begin();
                    }
                    s.erase(to_erase);
                    count--;
                    skip++;
                    k = 0;
                }
            }
            k++;
            it = next(it);
            if (it == s.end()) {
                it = s.begin();
            }
        }
        cout << *(s.begin()) << "\n";
    }

    return 0;
}