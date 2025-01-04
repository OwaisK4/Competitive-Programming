#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<vector<char>> square(n, vector<char>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> square[i][j];
        }
    }
    char diag, other;
    diag = square[0][0];
    other = square[0][1];
    bool diag_true = true, other_true = true;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j || i == (n - j - 1)){
                if (square[i][j] != diag){
                    diag_true = false;
                    break;
                }
            }
            else{
                if (square[i][j] != other){
                    other_true = false;
                    break;
                }
            }
        }
    }
    if (diag_true && other_true && (diag != other)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}