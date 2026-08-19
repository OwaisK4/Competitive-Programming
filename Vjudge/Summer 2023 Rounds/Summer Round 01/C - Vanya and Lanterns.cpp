#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

signed main(){
    fastio;
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(all(a));
    double dist = 0;

    for (int i=1; i<n; i++){
        dist = max(dist, (double) a[i] - a[i-1]);
    }
    dist = dist / 2.0;

    dist = max(dist, (double) a[0] - 0);
    dist = max(dist, (double) l - a[n-1]);

    cout << fixed << setprecision(9) << dist;

    return 0;
}