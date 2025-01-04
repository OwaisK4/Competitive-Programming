#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

int check(vector<vector<int>>& stage, int x, int y, int n, int m){
    int total = 0;
    for (int i = x; i < n; i++){
        if (stage[i][y] == 1){
            total++;
            break;
        }
    }
    for (int i = x; i >= 0; i--){
        if (stage[i][y] == 1){
            total++;
            break;
        }
    }

    for (int j = y; j < m; j++){
        if (stage[x][j] == 1){
            total++;
            break;
        }
    }
    for (int j = y; j >= 0; j--){
        if (stage[x][j] == 1){
            total++;
            break;
        }
    }
    // for (int i = x; i < n; i++){
    //     if (stage[i][y] == 1)
    //     total += stage[i][y];
    // }
    // for (int i = x; i >= 0; i--){
    //     total += stage[i][y];
    // }

    // for (int j = y; j < m; j++){
    //     total += stage[x][j];
    // }
    // for (int j = y; j >= 0; j--){
    //     total += stage[x][j];
    // }

    return total;
}

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> stage(n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> stage[i][j];
        }
    }
    int positions = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (stage[i][j] == 0)
                positions += check(stage, i, j, n, m);
        }
    }

    cout << positions;

    return 0;
}