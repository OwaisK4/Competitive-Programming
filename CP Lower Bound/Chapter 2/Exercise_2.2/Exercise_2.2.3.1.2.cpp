#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto& it : array){
        cout << it << " ";
    }
    cout << "\n";
}

void print(int a){
    int n = 5;      // Selected randomly. Should be 31 for int
    while (n >= 0){
        int bit = a & (1 << n);
        cout << (1 & (bit >> n));
        n--;
    }
    cout << "\n";
}

int main(){
    int S = 32;
    int T = __builtin_popcount(S);

    if (T == 0 || T == 1){
        cout << S << " is a power of two.\n";
    }
    else{
        cout << S << " is not a power of two.\n";
    }
}