#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int N, Q;
    int A, B;
    cin >> N >> Q;
    vector<int> bales(N);
    for (int i=0; i<N; i++){
        cin >> bales[i];
    }
    sort(all(bales));

    for (int i=0; i<Q; i++){
        cin >> A >> B;
        auto total = upper_bound(all(bales), B) - lower_bound(all(bales), A);
        cout << total << "\n";
    }
    // for (int i=0; i<Q; i++){
    //     cin >> A >> B;
    // }
    return 0;
}