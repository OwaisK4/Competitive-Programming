#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rep(i, a, b, n) for (int i=a; i != b, i<n; i++)
using namespace std;

int sum(long long int X){
    int answer = 0;
    bool dist = true;
    map<int, int> freq;
    while (X){
        int a = (X % 10);
        answer += a;
        X /= 10;
        freq[a]++;
    }
    for (auto it : freq){
        if (it.second > 1){
            dist = false;
            break;
        }
    }
    if (!dist){
        return -1;
    }
    else{
        return answer;
    }
}

int main() {
    int t, s;
    cin >> t;

    while (t--) {
        cin >> s;
        if (s <= 9) {
            cout << s << "\n";
        }
        else{
            // for (int i=0; i<10; i++){
            int answer = 0;
            int n = 1;
            for (int i=9; i>0; i--){
                if (s - i >= 0){
                    // answer = (answer * 10) + i;
                    answer = answer + (n * i);
                    n *= 10;
                    s -= i;
                }
            }
            if (s == 0){
                cout << answer << "\n";
                continue;
            }
            // }
        }
        // else{
            // for (long long int i = 0; i <= 123456789; i++){
            //     if (sum(i) == s){
            //         cout << i << "\n";
            //         break;
            //     }
            // }
        // }
    }
    return 0;
}