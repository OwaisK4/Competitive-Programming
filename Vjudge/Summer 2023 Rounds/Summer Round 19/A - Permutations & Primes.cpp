#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        if (n == 1){
            cout << 1 << "\n";
        }
        else if (n == 2){
            cout << 2 << " " << 1 << "\n";
        }
        else{
            vector<int> array(n, -1);
            array[n/2] = 1;
            array[0] = 2;
            array[n-1] = 3;
            int k = 4;
            for (int i=0; i<n; i++){
                if (array[i] == -1){
                    array[i] = k++;
                }
            }
            print(array);
        }
    }
    return 0;
}