#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long int n, a, b;
        cin >> n >> a >> b;
        if (a > b){
            cout << "1" << "\n";
            continue;
        }
        long long int count = 0;
        long long int sum = 0;
        // while (sum < n){
        //     sum += a;
        //     count++;
        // }

        while (n % a != 0){
            n++;
        }
        count = n / a;

        // long long int count = ceil(n / (float) a);
        // if (n % a != 0){
        //     while (count % a != 0){
        //         count++;
        //     }
        // }
        cout << count << "\n";
    }
    return 0;
}