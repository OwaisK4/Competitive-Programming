#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t, n;
    char d;
    cin >> t;
    bool flag = true;
    string s;
    while (t--){
        cin >> n >> d;
        cin >> s;
        if (d == '0'){
            s += d;
        }
        else{
            for (int i=0; i<n; i++){
                if (i > 0 && s[i] > s[i-1]){
                    s += d;
                    // flag = false;
                    break;
                }
                if (s[i] <= d){
                    s.insert(i, 1, d);
                    break;
                }
            }
            // if (!flag){
            //     s += d;
            //     for (int i=n-1; i>=0; i--){
            //         if (s[i] >= d){
            //             s.insert(i+1, 1, d);
            //             break;
            //         }
            //     }
            // }
        }
        cout << s << "\n";
    }

    return 0;
}