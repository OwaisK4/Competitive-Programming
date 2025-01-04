#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;
bool flag = false;

template <typename T>
void debug(T array, int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

/*
void solve(vector<int> a, vector<int> b, int& N, int& X, int i = 0, int counter = 0){
    if (N == i){
        if (counter == X){
            flag = true;
            cout << "Yes";
        }
        else{
            return;
        }
    }
    if (counter > X){
        return;
    }
    solve(values, N, X, i+1, counter+a[i]);
    solve(values, N, X, i+1, counter+b[i]);
    // exit(0);
}
*/

void dp_solve(vector<int> a, vector<int> b){
    const int X = 100001;
    const int N = 100;

    // bool dp[N][X] = {0};
    // dp[0][a[0]] = true;
    // dp[0][b[0]] = true;

    bool dp[X] = {0};

    dp[a[0]] = true;
    dp[b[0]] = true;

    for (int i=1; i<N; i++){
        for (int j=0; j<X; j++){
            if (j - a[i] >= 0)
                dp[j] |= dp[j - a[i]];
            if (j - b[i] >= 0)
                dp[j] |= dp[j - b[i]];
        }
    }
    debug(dp, 11);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    int a, b;
    // vector<pair<int, int>> values;
    vector<int> vec_A, vec_B;

    cin >> N >> X;
    for (int i=0; i<N; i++){
        cin >> a >> b;
        vec_A.push_back(a);
        vec_B.push_back(b);
        // values.push_back({a, b});
    }

    dp_solve(vec_A, vec_B);
    // solve(values, N, X);
    // if (!flag){
    //     cout << "No";
    // }
    return 0;
}