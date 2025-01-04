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

vector<int> a;

signed main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        a.assign(p, 1);
        int count = p;
        int k = 0;
        int skip = 0;
        int i = 0;
        while (count > 1) {
            print(a);
            i %= p;
            if (a[i] == 1) {
                if (k == skip) {
                    a[i] = 0;
                    count--;
                    skip++;
                    k = -1;
                }
                k++;
            }
            i++;
        }
        for (i = 0; i < p; i++) {
            if (a[i] == 1) {
                break;
            }
        }
        cout << i + 1 << "\n";
    }

    return 0;
}