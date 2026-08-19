#include <bits/stdc++.h>
#include <ext/numeric>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int N, X;
    cin >> N >> X;
    vector<int> a(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int sum1 = accumulate(a.begin(), a.end() - 1, 0);
    int sum2 = accumulate(a.begin() + 1, a.end() - 1, 0);
    int sum3 = accumulate(a.begin() + 1, a.end(), 0);

    if (sum1 >= X) {
        cout << 0;
        return 0;
    }

    int element1 = (max(0LL, X - sum2));
    if (element1 > 100) {
        element1 = -1;
    }

    int element2 = -1;
    if (sum3 >= X) {
        element2 = *max_element(all(a));
    }

    if (element1 != -1 && element2 != -1) {
        cout << min(element1, element2);
    } else {
        cout << -1;
    }

    return 0;
}