#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> a(n), b(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    ll zeroes = 0;
    for (int i=0; i<n; i++){
        cin >> b[i];
        if (a[i] == '0'){
            zeroes++;
        }
    }
    zeroes *= 2;
    cout << zeroes;
    
    return 0;
}