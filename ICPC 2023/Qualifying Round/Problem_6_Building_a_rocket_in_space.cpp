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

int n;
vector<int> a;

int f(int l, int r, int sum) {
    if (l == r) {
        return 0;
    }
    if (r - l + 1 == 2) {
        sum += a[l] + a[r];
        return sum;
    }
    int left = 0;
    int right = 0;
    int x = 1e18;
    for (int k = l; k < r; k++) {
        left = f(l, k, sum + a[l] + a[r]);
        right = f(k + 1, r, sum + a[l] + a[r]);
        x = min(x, left + right);
    }
    return x;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;

        while (getline(ss, temp, ' ')) {
            a.push_back(stoll(temp));
        }
        n = a.size();

        int answer = f(0, n - 1, 0);
        cout << answer << "\n";
        a.clear();
    }

    return 0;
}