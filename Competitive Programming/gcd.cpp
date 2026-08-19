#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

int GCD(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

signed main(){
    int a = 3;
    int b = 6;

    // int c = gcd(a, b);
    int c = GCD(a, b);
    cout << "GCD of a=" << a << " and b=" << b << " is: " << c << "\n";
    return 0;
}