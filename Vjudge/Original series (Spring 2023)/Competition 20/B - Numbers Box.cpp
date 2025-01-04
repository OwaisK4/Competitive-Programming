#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t, n, m;
    cin >> t;

    while (t--){
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        long long int X = 0;
        int minimum = INT_MAX;
        int negatives = 0;
        bool zero_flag = false;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> grid[i][j];
                if (grid[i][j] == 0)
                    zero_flag = true;
                else if (grid[i][j] < 0)
                    negatives++;
                X += abs(grid[i][j]);
                minimum = min(minimum, abs(grid[i][j]));
            }
        }

        if (negatives % 2 == 0 || zero_flag){
            cout << X << "\n";
            continue;
        }
        else{
            X -= (2 * minimum);
            cout << X << "\n";
            continue;
        }
    }

    return 0;
}