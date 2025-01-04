#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
using namespace std;

int main(){
    int n, q;
    map<int, int, greater<int>> coins;
    cin >> n >> q;
    int a;
    for (int i=0; i<n; i++){
        cin >> a;
        coins[a]++;
    }
    while (q--){
        int b;
        cin >> b;
        int sum = 0;
        for (auto it : coins){
            int num_coins = b / it.first;
            num_coins = min(num_coins, it.second);
            b -= (it.first * num_coins);
            sum += num_coins;
        }
        if (b > 0){
            cout << "-1" << "\n";
        }
        else{
            cout << sum << "\n";
        }
    }
    return 0;
}