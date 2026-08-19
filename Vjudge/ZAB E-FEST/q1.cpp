#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main(){
    int N;
    cin >> N;

    int a=0, b=1;

    cout << 0 << " ";
    while (a < N){
        cout << b << " ";
        int c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
