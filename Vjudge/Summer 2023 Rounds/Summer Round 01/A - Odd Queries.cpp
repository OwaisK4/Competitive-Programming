#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

signed main(){
    fastio;
    int t;
    cin >> t;
    int n, q;
    int l, r, k;
    while (t--){
        cin >> n >> q;
        vector<int> a(n);
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<int> prefix(n+1);
        partial_sum(all(a), prefix.begin() + 1);
        for (int i=0; i<q; i++){
            cin >> l >> r >> k;
            int k_sum = (r - l + 1) * k;
            int remaining = (prefix[n] - prefix[r]);
            remaining += (prefix[l-1] - prefix[0]);
            int answer = k_sum + remaining;
            if (answer % 2 == 0){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}