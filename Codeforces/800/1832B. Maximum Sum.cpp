#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));

        vector<int> prefix(n);
        partial_sum(all(a), prefix.begin());

        // for (auto it : prefix){
        //     cout << it << " ";
        // }
        // cout << "\n";

        int answer = prefix[n - k - 1];
        for (int i = 0; i < k; i++) {
            answer = max(answer, prefix[n - (k - i)] - prefix[2 * i + 1]);
        }
        cout << answer << "\n";
    }
    return 0;
}