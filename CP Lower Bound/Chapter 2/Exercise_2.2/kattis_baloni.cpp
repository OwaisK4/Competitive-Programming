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
    int N, H;
    cin >> N;
    vector<int> counter(N + 1);
    int arrows = 0;

    for (int i=0; i<N; i++){
        cin >> H;
        if (counter[H] == 0){
            counter[H-1]++;
            arrows++;
        }
        else{
            counter[H]--;
            counter[H-1]++;
        }
    }
    cout << arrows;
}