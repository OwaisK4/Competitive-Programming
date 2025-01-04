#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> dp(1, 0);

int f(int h){
    if (h == 1){
        return 2;
    }
    else{
        int answer = f(h-1) + h*f(1) + h - 1;
        return answer;
    }
}

void fill_dp(int n){        // n = 1 x 10^9 since that is program constraint
    int i = 1;
    int current = 2;
    dp.push_back(current);  i++;
    while (current < n){
        current = dp[i - 1] + (i * dp[1]) + i - 1;
        dp.push_back(current);
        i++;
    }
}

signed main(){
    fastio;
    int limit = 1e9;
    fill_dp(limit);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int counter = 0;
        while (n >= 2){
            auto it = lower_bound(all(dp), n);
            if (*it == n){
                n -= *it;
                counter++;
                break;
            }
            if (it-1 == dp.begin()){
                break;
            }
            int value = *(it - 1);
            n -= value;
            counter++;
        }
        cout << counter << "\n";
    }

    return 0;
}