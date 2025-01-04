#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, m, k;
        cin >> n >> m >> k;
        
        if (m == 0 || m == 1){
            cout << m << "\n";
            continue;
        }
        int cards = n / k;
        if (cards == 1){
            cout << 0 << "\n";
            continue;
        }
        if (cards >= m){
            cout << m << "\n";
            continue;
        }
        else{
            m = m - cards;
            k--;
            if (m == cards && k == 1){
                cout << 0 << "\n";
            }
            else{
                int second = ceil((float) m / (float) k);
                cout << (cards - second) << "\n";
            }
        }
    }
    return 0;
}