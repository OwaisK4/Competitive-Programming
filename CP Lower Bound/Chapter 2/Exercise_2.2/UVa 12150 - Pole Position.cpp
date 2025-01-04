#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto& it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    int n;
    while (true){
        cin >> n;
        if (n == 0){
            break;
        }
        vector<int> cars(n);
        vector<int> positions(n);
        for (int i=0; i<n; i++){
            cin >> cars[i];
            cin >> positions[i];
        }
        vector<int> start_grid(n, 0);
        bool invalid = false;
        for (int i=0; i<n; i++){
            int pos = i + positions[i];
            if (pos < 0 || pos > n){
                invalid = true;
                break;
            }
            if (start_grid[pos] != 0){
                invalid = true;
                break;
            }
            start_grid[pos] = cars[i];
        }
        if (invalid){
            cout << -1 << "\n";
        }
        else{
            // for (auto& it : start_grid){
            //     cout << it << " ";
            // }
            for (int i=0; i<n; i++){
                if (i == n-1){
                    cout << start_grid[i];
                }
                else{
                    cout << start_grid[i] << " ";
                }
            }
            cout << "\n";
        }
    }
}