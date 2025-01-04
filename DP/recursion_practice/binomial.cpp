#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;
vector<vector<int>> dp(1e3 + 1, vector<int>(1e3 + 1, 0));

int binomial(int N, int K){
    if (dp[N][K] != 0){
        return dp[N][K];
    }
    if (K == 0 || N == K){
        return 1;
    }
    int coeff = binomial(N-1, K-1) + binomial(N-1, K);
    return dp[N][K] = coeff;
    // return coeff;
}

signed main(){
    int N, K;
    N = 50;
    K = 23;
    // cin >> N >> K;

    int answer = binomial(N, K);
    cout << answer << "\n";
    
    return 0;
}