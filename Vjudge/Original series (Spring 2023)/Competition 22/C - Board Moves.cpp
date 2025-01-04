#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 0 << "\n";
            continue;
        }
        n = n / 2;
        long long int sum = 0;
        long long int boxes = 8;
        long long int mul = 1;

        while (n > 0){
            sum += (boxes * mul);
            boxes += 8;
            mul++;
            n--;
        }
        cout << sum << "\n";
    }
    return 0;
}