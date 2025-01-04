#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

void solve(){
    int N, Q;
    cin >> N >> Q;
    int temp;
    vector<int> X_positives(2*N + 1, 0), X_negatives(2*N + 1, 0), R(N, 0), sign(N);
    vector<bool> bomb_negative(2*N + 1, false), bomb_positive(2*N + 1, false);
    for (int i=0; i<N; i++){
        cin >> temp;
        if (temp < 0){
            X_negatives[abs(temp)]++;
            sign[i] = 0;
            bomb_negative[abs(temp)] = true;
        }
        else{
            X_positives[abs(temp)]++;
            sign[i] = 1;
            bomb_positive[abs(temp)] = true;
        }
    }
    for (int i=0; i<N; i++){
        // cin >> R[i];
        int R;
        cin >> R;
        if (sign[i] == 1){
            if (!bomb_positive[i]){
                continue;
            }
            for (int j=1; j <= R; j++){
                // if (X_positives[i] + j <= 2*N){
                //     X_positives[X_positives[i] + j]++;
                // }
                // if (X_positives[i] - j > 0){
                //     X_positives[X_positives[i] - j]++;
                // }
                if (i + j <= 2*N){
                    X_positives[i + j]++;
                }
                if (i - j > 0){
                    X_positives[i - j]++;
                }
            }
        }
        else{
            if (!bomb_negative[i]){
                continue;
            }
            for (int j=1; j <= R; j++){
                // if (X_negatives[i] + j <= 2*N){
                //     X_negatives[X_negatives[i] + j]++;
                // }
                // if (X_negatives[i] - j > 0){
                //     X_negatives[X_negatives[i] - j]++;
                // }
                if (i + j <= 2*N){
                    X_negatives[i + j]++;
                }
                if (i - j > 0){
                    X_negatives[i - j]++;
                }
            }
        }
    }
    for (int i=0; i<Q; i++){
        cin >> temp;
        if (temp < 0){
            cout << X_negatives[abs(temp)] << "\n";
        }
        else{
            cout << X_positives[abs(temp)] << "\n";
        }
    }

    for (int i=0; i<=2*N; i++){
        cout << X_positives[i] << " ";
        // cout << X_negatives[i] << " ";
    }
}

signed main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}