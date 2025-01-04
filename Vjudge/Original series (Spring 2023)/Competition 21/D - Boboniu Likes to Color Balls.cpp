#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, g, b, w;
        vector<int> balls(4);
        vector<int> odd(4);
        for (int i = 0; i < 4; i++) {
            cin >> balls[i];
            odd[i] = balls[i] % 2;
        }
        // for (int i = 0; i < 4; i++) {
        //     // cout << balls[i] << " ";
        //     cout << odd[i] << " ";
        // }
        while (true) {
            if (balls[0] == balls[1] && balls[1] == balls[2] && balls[2] == balls[3]){
                cout << "YES\n";
                break;
            }
            else if (count(all(balls), 0) == 4) {
                cout << "YES\n";
                break;
            }
            else if (count(all(odd), 1) == 1 || count(all(odd), 1) == 0) {
                cout << "YES\n";
                break;
            }
            else if (count(all(balls), 0) > 0) {
                if (balls[0] == 0 || balls[1] == 0 || balls[2] == 0) {
                    cout << "NO\n";
                    break;
                }
            }
            else{
                balls[0]--;
                balls[1]--;
                balls[2]--;
                balls[3]++;
            }
            for (int i = 0; i < 4; i++) {
                odd[i] = balls[i] % 2;
            }
        }
    }

    return 0;
}