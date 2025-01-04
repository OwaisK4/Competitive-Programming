#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vector<vector<int>> a;
// vector<vector<bool>> visited;
int total = 0;

int dfs(int x, int y, int& n, int& m){
    if (x < 0 || y < 0 || x >= n || y >= m){
        return total;
    }
    if (a[x][y] == 0){
        return total;
    }
    total += a[x][y];
    a[x][y] = 0;
    dfs(x-1, y, n, m);
    dfs(x, y-1, n, m);
    dfs(x+1, y, n, m);
    dfs(x, y+1, n, m);
    return total;
}

signed main(){
    fastio;
    int t, n, m;
    cin >> t;
    while (t--){
        cin >> n >> m;
        a.assign(n, vector<int>(m, 0));
        // visited.assign(n, vector<bool>(m, false));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }
        int volume = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                volume = max(volume, dfs(i, j, n, m));
                total = 0;
            }
        }
        cout << volume << "\n";
    }
    return 0;
}