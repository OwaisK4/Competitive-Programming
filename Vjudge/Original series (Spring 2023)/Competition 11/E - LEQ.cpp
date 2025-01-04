#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    long long int A[N];
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    long long int count = 0;
    // long long int consecutive = 0;
    // long long int max = numeric_limits<long long int>::min();
    // long long int max = A[0];
    // int dp[N][N] = {};
    

    /*
    int dp[N+1] = {};
    for (int i=0; i<N-1; i++){
        if (A[i] <= A[i+1]){
            dp[i+1] = dp[i] + 1;
        }
        else{
            dp[i+1] = dp[i];
        }
    // A[i] %= 998244353;
    }
    cout << dp[N-1];
    */

    /*
    for (int i = 0; i < N-1; i++){
        consecutive = 0;
        for (int j = i+1; j < N; j++){
            if (A[i] <= A[j]){
                consecutive++;
                count += consecutive;
                count %= 998244353;
            }
            else{
                consecutive = 0;
            }
            if (max < A[j])
                max = A[j];
        }
        if (A[i] == max)
            break;
    }
    cout << count;
    */
    return 0;
}