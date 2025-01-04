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
    int cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        cnt++;
        int key = arr[i + 1];
        if (key < arr[i]) {
            int j = i + 2;
            while (j < n && arr[j] < key) {
                j++;
                cnt++;
            }
        }
    }
    cout << cnt;
}