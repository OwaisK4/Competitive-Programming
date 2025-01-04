#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

int is_adjacent(int x, int y, vector<vector<char>> board, int n){
    if (x >= 0 && y >= 0 && x < n && y < n){
        if (board[x][y] == 'o')
            return 1;
    }
    return 0;
}

signed main(){
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int adj_cells = 0;
            adj_cells += is_adjacent(i, j-1, board, n);
            adj_cells += is_adjacent(i, j+1, board, n);
            adj_cells += is_adjacent(i-1, j, board, n);
            adj_cells += is_adjacent(i+1, j, board, n);
            if (adj_cells % 2 != 0){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}