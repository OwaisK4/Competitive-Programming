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
    int N;
    cin >> N;
    vector<int> A(N), GIS;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    int start = 0;
    int count = 0;
    for (int i=0; i<N; i++){
        if (A[i] > start){
            GIS.push_back(A[i]);
            start = A[i];
            count++;
        }
    }
    cout << count << "\n";
    for (auto& it : GIS){
        cout << it << " ";
    }
    return 0;
}