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
    while (cin >> n){
        vector<int> values(n);
        set<int> s;

        for (int i=0; i<n; i++){
            cin >> values[i];
        }
        for (int i=1; i<n; i++){
            int diff = abs(values[i] - values[i-1]);
            if (diff > n-1){
                break;
            }
            s.insert(diff);
        }
        if (s.size() == n-1){
            cout << "Jolly\n";
        }
        else{
            cout << "Not jolly\n";
        }
    }
}