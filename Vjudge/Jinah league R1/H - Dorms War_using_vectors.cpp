#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN

using namespace std;

signed main(){
    int t, n, k;
    string s;
    char special;

    cin >> t;
    while (t--){
        cin >> n >> s;
        cin >> k;
        vector<char> c(26, 0);
        for (int i=0; i<k; i++){
            cin >> special;
            c[special - 97] = 1;
        }

        int dist = 0;
        int last=0, current=0;
        for (current = 0; current < n; current++){
            if (c[s[current] - 97] != 0){
                dist = max(dist, current - last);
                last = current;
            }
        }
        cout << dist << "\n";
    }
}