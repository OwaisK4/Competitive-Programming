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

int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18;

signed main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        v0 = A;
        v1 = B;
        v2 = C;
        v3 = 1;
        v4 = 0;
        v5 = v4 - v3;
        v6 = v3;
        v7 = v4;
        v7 = v7 - v1;
        v8 = v0;
        v9 = v0 + v1;

        v10 = v4;
        v11 = v4;
        v12 = v3;
    l0:
        v11 += v1;
        v10 += v0;
        v13 = v10;
        v14 = v4;
        v15 = v4;
    l1:
        v16 = v13 + v13;
        if (v16 <= v1) {
            goto l2;
        }
        v13 -= v1;
        v14 += v3;
        v15 += v1;
        goto l1;
        // int n = (v13 + v13 + v1 - 1) / v1;
        // v13 -= (n * v1);
        // v14 += (n * v3);
        // v15 += (n * v1);
    l2:
        if (v13 > v4) {
            goto l3;
        }
        v13 = v4 - v13;

    l3:
        v17 = v4;
        v18 = v3;

    l4:
        v17 += v13;
        v18 += v3;
        if (v18 <= v6) {
            goto l4;
        }
        v18 = v3;

    l5:
        v17 -= v9;
        v18 += v3;
        if (v18 <= v12) {
            goto l5;
        }
        if (v17 >= v4) {
            goto l6;
        }
        v5 = v14;
        v6 = v12;
        v7 = v15;
        v8 = v10;
        v9 = v13;

    l6:
        v12 += v3;
        if (v12 <= v2) {
            goto l0;
        }
        cout << v6 << "\n";
    }

    return 0;
}