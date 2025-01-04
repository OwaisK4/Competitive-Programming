#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN

using namespace std;

signed main(){
    int t, n;
    string s;
    cin >> t;

    while (t--){
        cin >> n;
        cin >> s;

        int count = 1;
        for (int i=0; i<n; i++){
            if (i < n-2 && s[i] != s[i+2]){
                count++;
            }
        }
        cout << count << "\n";
    }

}