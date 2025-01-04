#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, h0, a, c, q;
    cin >> n >> h0 >> a >> c >> q;
    vector<int> arr(n, 0);
    arr[0] = h0;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + c) % q;
    }
    vector<int> pre(n, 0);
    pre[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pre[i];
    }
    cout << sum;
}