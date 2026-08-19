#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main(){
    int w;
    cin >> w;

    int a = 1, b = w/2 - 1;
    while (a <= b){
        if (2*a + 2*b == w){
            cout << "YES";
            return 0;
        }
        a++;
        b--;
    }
    cout << "NO";
    return 0;
}