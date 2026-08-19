#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

void solve(){
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n), b(n);
    
    for (auto& it : a){
        cin >> it;
    }
    for (auto& it : b){
        cin >> it;
    }

    for_each(all(a), [](int x){cout << x << " ";});
    cout << "\n";
    for_each(all(b), [](int x){cout << x << " ";});
    cout << "\n";

    int leftmost = INT_MIN;
    int rightmost = INT_MAX;

    for (int i=0; i<n; i++){
        int left = (b[i] + h) - (a[i] + w);
        int right = (b[i] - h) - (a[i] - w);

        leftmost = max(leftmost, left);
        rightmost = min(rightmost, right);
    }
    if (leftmost <= rightmost){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}