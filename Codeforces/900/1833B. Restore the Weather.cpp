#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;
using pii = pair<int, int>;

signed main(){
    int t;
    cin >> t;

    int n, k;
    while (t--){
        cin >> n >> k;
        
        vector<pii> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i=0; i<n; i++){
            cin >> b[i];
        }
        sort(all(a));
        sort(all(b));
        
        for (int i=0; i<n; i++){
            a[i].first = b[i];
            swap(a[i].first, a[i].second);
        }
        sort(all(a));

        for (auto it : a){
            cout << it.second << " ";
        }
        cout << "\n";
    }
    return 0;
}