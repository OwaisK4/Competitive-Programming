#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t, n, m, x, y;
    cin >> t;

    while (t--){
        cin >> n >> m >> x >> y;
        vector<vector<char>> square(n, vector<char>(m));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> square[i][j];
            }
        }
        int price = 0;
        if (2*x <= y){
            int singles = 0;
            for (int i=0; i<n; i++){
                singles += count(all(square[i]), '.');
            }
            price = (singles * x);
            cout << price << "\n";
        }
        else{
            int singles = 0;
            int doubles = 0;
            for (int i=0; i<n; i++){
                for (int j=0; j<m-1; j++){
                    if (square[i][j] == '.' && square[i][j+1] == '.'){
                        doubles++;
                        square[i][j] = '*';
                        square[i][j+1] = '*';
                    }
                }
            }
            for (int i=0; i<n; i++){
                singles += count(all(square[i]), '.');
            }
            price = (x * singles) + (y * doubles);
            // cout << "Singles = " << singles << " doubles = " << doubles << " ";
            cout << price << "\n";
        }
    }

    return 0;
}