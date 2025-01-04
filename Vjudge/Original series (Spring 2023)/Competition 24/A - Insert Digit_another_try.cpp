#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long 
using namespace std;

signed main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        char d;
        cin >> n >> d;
        string s;
        cin >> s;
        
        bool flag = false;
        for (int i=0; i<n; i++){
            if (s[i] < d){
                s.insert(s.begin() + i, d);
                flag = true;
                break;
            }
        }
        if (!flag){
            s.push_back(d);
        }
        cout << s << "\n";
    }
    return 0;
}