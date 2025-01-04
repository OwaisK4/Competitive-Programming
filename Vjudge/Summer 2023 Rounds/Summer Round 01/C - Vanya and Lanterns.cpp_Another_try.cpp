#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(deque<T> array){
    for (auto& it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int n, l;
    cin >> n >> l;

    deque<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(all(a));
    // print(a);

    double dist = 0;
    if (n == 1){
        dist = max(dist, (double) a[0] - 0);
        dist = max(dist, (double) l - a[0]);
    }
    else{
        // dist = max(dist, (double) a[0] - 0);
        // dist = max(dist, (double) l - a[n-1]);
        // print(a);
        for (int i=1; i<n-1; i++){
            // double left = (a[i] - a[i-1]) / 2.0;
            // double right = (a[i+1] - a[i]) / 2.0;
            double left = (a[i] - a[i-1]);
            double right = (a[i+1] - a[i]);
            dist = max(dist, max(left, right));
        }

        dist = max(dist, (double) a[0] - 0);
        dist = max(dist, (double) l - a[n-1]);
        // dist = max(dist, (a[1] - 0) / 2.0);
        // cout << "dist = " << dist << "\n";
        // dist = max(dist, (l - a[n-2]) / 2.0);
        // cout << "dist = " << dist << "\n";
        // for (int i=1; i<n-2; i++){
        //     dist = max(dist, (a[i+1] - a[i-1]) / 2.0);
        //     cout << "dist = " << dist << "\n";
        // }
    }
    cout << fixed << setprecision(9) << dist;
    // cout << dist;

    // print(diff);

    return 0;
}