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
    int t;
    int n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(all(a));
        int current = a[0];
        vector<int> remaining;
        cout << current << " ";
        for (int i=1; i<n; i++){
            if (a[i] == current){
                remaining.push_back(a[i]);
            }
            else{
                cout << a[i] << " ";
            }
            current = a[i];
        }
        for (auto it : remaining){
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}