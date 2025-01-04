#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vi coins;
vi dp;

vector<int> digits(int x){
    vector<int> answer;
    while (x > 0){
        int digit = x % 10;
        if (digit > 0)
            answer.push_back(digit);
        x /= 10;
    }
    return answer;
}

int minimal(int sum){
    if (sum == 0){
        return 0;
    }
    if (sum < 0){
        return LONG_LONG_MAX - 1;
    }
    if(dp[sum]!=-1)
        return dp[sum];
    vector<int> array = digits(sum);
    int answer = LONG_LONG_MAX;
    for (auto it : array){
        answer = min(answer, minimal(sum - it) + 1);
    }
    return dp[sum] = answer;
}
void fill_dp(){
    dp[0] = 0;
    for (int i=1; i<dp.size(); i++){
        vector<int> arr = digits(i);
        for (auto it : arr){
            if (i - it >= 0){
                dp[i] = min(dp[i], dp[i - it] + 1);
            }
        }
    }
}
signed main(){
    fastio;
    int n;
    cin >> n;
    dp.assign(n+1, LONG_LONG_MAX);
    // cout << minimal(n) << "\n";
    fill_dp();
    cout<<dp[n]<<endl;
    return 0;
}