#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vector<vector<int>> prices;
vector<vector<int>> dp;
int M, C;

int f(int i, int money){
    if (money < 0){
        return LONG_LONG_MIN;
    }
    if (dp[i][money] != -1){
        return dp[i][money];
    }
    if (i == C){
        return dp[i][money] = M - money;
    }
    int answer = -1;
    for (auto it : prices[i]){
        answer = max(answer, f(i+1, money - it));
    }
    return dp[i][money] = answer;
}

signed main(){
    fastio;
    int N;
    cin >> N;
    while (N--){
        cin >> M >> C;
        dp.assign(C+1, vector<int>(M+1, -1));
        prices.assign(C, vector<int>());
        for (int i=0; i<C; i++){
            int K, temp;
            cin >> K;
            for (int j=0; j<K; j++){
                cin >> temp;
                prices[i].push_back(temp);
            }
        }
        int answer = f(0, M);
        if (answer != -1){
            cout << answer << "\n";
        }
        else{
            cout << "no solution" << "\n";
        }
    }
    return 0;
}