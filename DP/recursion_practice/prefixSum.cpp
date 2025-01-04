#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

signed main(){
    int N, K;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i=0; i<N; i++){
        a[i] = i + 1;
    }

    for (auto it : a){
        cout << it << " ";
    }
    cout << "\n";

    partial_sum(all(a), b.begin());
    for (auto it : b){
        cout << it << " ";
    }
    cout << "\n";

    
    return 0;
}