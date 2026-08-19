#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int n, c;
    cin >> n >> c;
    vector<int> prices(n), diff(n-1);
    for (int i=0; i<n; i++){
        cin >> prices[i];
    }
    for (int i=0; i<n-1; i++){
        diff[i] = prices[i] - prices[i+1];
    }
    int max_diff = diff[0];
    int max_day = 0;

    for (int i=1; i<n-1; i++){
        if (diff[i] > max_diff){
            max_diff = diff[i];
            max_day = i;
        }
    }

    int answer = max_diff - c;
    if (answer < 0){
        cout << 0;
    }
    else{
        cout << answer;
    }

    return 0;
}