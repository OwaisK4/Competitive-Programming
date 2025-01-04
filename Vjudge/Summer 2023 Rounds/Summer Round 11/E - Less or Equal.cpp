#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(all(a));

    if (k == 0){
        if (a[0] == 1){
            cout << -1;
        }
        else{
            cout << 1;
        }
    }
    else if (k == n){
        cout << a[k-1];
    }
    else{
        if (a[k-1] == a[k]){
            cout << -1;
        }
        else{
            cout << a[k-1];
        }
    }

    return 0;
}