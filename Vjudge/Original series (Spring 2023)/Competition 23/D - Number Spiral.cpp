#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long int y, x;
        long long int count;
        cin >> y >> x;

        // if (y < x){
        //     swap(y, x);
        // }

        if (y >= x){
            x--;
            if (y % 2 == 0){
                count = y * y;
                count -= x;
            }
            else{
                y--;
                count = y * y;
                count++;
                count += x;
            }
        }
        else{
            y--;
            if (x % 2 == 1){
                count = x * x;
                count -= y;
            }
            else{
                x--;
                count = x * x;
                count++;
                count += y;
            }
        }
        cout << count << "\n";
    }
    return 0;
}