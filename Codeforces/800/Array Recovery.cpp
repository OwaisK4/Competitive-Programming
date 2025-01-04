#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> a1(n), a2(n), d(n);
        for (int i=0; i<n; i++){
            cin >> d[i];
        }
        a1[0] = d[0];
        a2[0] = d[0];
        bool flag_A = true, flag_B = true;
        for (int i=1; i<n; i++){
            a1[i] = a1[i-1] + d[i];
            a2[i] = a2[i-1] - d[i];
            // cout << "a1[i] = " << a1[i] << " a2[i] = " << a2[i] << "\n";
            if (a1[i] < 0){
                flag_A = false;
            }
            if (a2[i] < 0){
                flag_B = false;
            }
        }
        if (flag_A && flag_B){
            cout << "-1";
        }
        else if (flag_A){
            for (auto it : a1){
                cout << it << " ";
            }
        }
        else{
            for (auto it : a2){
                cout << it << " ";
            }
        }
        cout << "\n";
    }
}