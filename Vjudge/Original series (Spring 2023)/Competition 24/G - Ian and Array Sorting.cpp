#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        if (n % 2 == 1){
            cout << "YES\n";
        }
        else{
            if (n == 2){
                if (a[0] > a[1]){
                    cout << "NO\n";
                }
                else{
                    cout << "YES\n";
                }
                continue;
            }
            bool flag = true;
            for (int i=0; i<n-2; i++){
                if (a[i] > a[i+1] && a[i+1] < a[i+2]){
                    flag = false;
                    break;
                }
            }
            if (!flag){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}