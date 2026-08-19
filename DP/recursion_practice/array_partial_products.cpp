#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long int
using namespace std;

int multiply(int a, int b){
    return a * b;
}

signed main(){
    int N = 7;
    // cin >> N;

    vector<int> a(N);
    iota(all(a), 1);

    cout << "Original array: ";
    for (int it : a){
        cout << it << " ";
    }
    cout << "\n";

    vector<int> prefix(N), suffix(N);
    partial_sum(all(a), prefix.begin(), multiply);
    partial_sum(rall(a), suffix.rbegin(), multiply);

    cout << "Prefix array: ";
    for (int it : prefix){
        cout << it << " ";
    }
    cout << "\n";

    cout << "Suffix array: ";
    for (int it : suffix){
        cout << it << " ";
    }
    cout << "\n";

    vector<int> result(N);
    result[0] = suffix[1];
    result[N-1] = prefix[N-2];
    for (int i=1; i<N-1; i++){
        result[i] = prefix[i-1] * suffix[i+1];
    }

    cout << "\n";
    cout << "Answer array: ";
    for (int it : result){
        cout << it << " ";
    }
    cout << "\n";
    
    return 0;
}