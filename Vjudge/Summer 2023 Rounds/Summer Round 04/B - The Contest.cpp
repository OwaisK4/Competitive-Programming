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
    int n, m;
    cin >> n;
    vector<int> times(n);
    int sum = 0;
    for (int i=0; i<n; i++){
        cin >> times[i];
        sum += times[i];
    }

    cin >> m;
    vector<pair<int, int>> periods(m);
    for (auto & [start, end] : periods){
        cin >> start >> end;
    }
    
    int counter = -1;

    for (auto & [start, end] : periods){
        if (sum >= start && sum <= end){
            counter = sum;
        }
        if (sum < start && counter == -1){
            counter = start;
        }
    }

    cout << counter;

    return 0;
}