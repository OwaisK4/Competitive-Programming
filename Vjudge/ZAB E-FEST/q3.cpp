#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main(){
    vector<int> coins = {1,5,7,9,11};
    vector<int> generated;
    int num = 0, sum = 0;
    int req = 20;

    sort(all(coins), greater<int>());
    for (int i=0; i<coins.size(); i++){
        if (sum + coins[i] <= req){
            sum += coins[i];
            generated.push_back(coins[i]);
            num++;
            i--;
        }
    }

    cout << "{";
    for (auto it : generated){
        cout << it << " ";
    }
    cout << "}";

    return 0;
}
