#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    while (t--){
        cin >> n >> x;
        long long int sum = 0;
        vector<int> a(n);
        for (int i=0; i<n-1; i++){
            cin >> a[i];
            sum += a[i];
        }
        ll answer = n*x - sum;
        if (answer < 0){
            answer = 0;
        }
        cout << answer << "\n";
    }
    return 0;
}