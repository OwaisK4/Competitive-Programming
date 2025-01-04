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
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> V;

    for (int i=0; i<N; i++){
        int X;
        cin >> X;
        V.push_back({X, 1LL});
        V.push_back({X + 1000,-1LL});
    }
    sort(all(V));
    int count = 0;
    int max_count = K;

    // for (auto & [X, mark] : V){
    //     cout << mark << " ";
    // }
    // cout << "\n";

    for (auto & [X, mark] : V){
        count += mark;
        if (count > max_count){
            max_count += K;
        }
    }
    cout << max_count / K;
}