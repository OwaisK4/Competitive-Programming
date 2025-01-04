#include <bits/stdc++.h>
// #define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
using namespace std;

void solve(){
    int N, Q;
    cin >> N >> Q;
    int temp;
    vector<int> X_positives(2*N + 1, 0), X_negatives(2*N + 1, 0), R(N, 0);
    vector<int> bombs(2*N + 1);
    for (int i=0; i<N; i++){
        cin >> temp;
        bombs[i] = temp;
        // bombs.push_back(temp);
        if (temp < 0){
            X_negatives[abs(temp)]++;
        }
        else{
            X_positives[abs(temp)]++;
        }
    }
    for (int i=0; i<N; i++){
        int R;
        cin >> R;
        int b = bombs[i];
        if (b > 0){
            for (int j=1; j <= R; j++){
                if (b + j <= 2*N){
                    X_positives[b + j]++;
                }
                if (b - j > 0){
                    X_positives[b - j]++;
                }
            }
        }
        else{
            b = abs(b);
            for (int j=1; j <= R; j++){
                if (b + j <= 2*N){
                    X_negatives[b + j]++;
                }
                if (b - j > 0){
                    X_negatives[b - j]++;
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

    // for (int i=0; i<=2*N; i++){
    //     cout << X_positives[i] << " ";
    //     cout << X_negatives[i] << " ";
    // }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}