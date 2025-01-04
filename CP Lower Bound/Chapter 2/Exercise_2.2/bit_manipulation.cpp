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
    int n = 5;
    while (n >= 0){
        int bit = a & (1 << n);
        cout << (1 & (bit >> n));
        n--;
    }
    cout << "\n";
}

signed main(){
    mt19937 mt(seed);
    uniform_int_distribution<int> uid(0, 9);
    int S = 34;     //pow(-2, 31);
    int j;
    print(S);

    // Setting j-th bit
    j = 3;
    S |= (1 << j);
    print(S);

    // Clearing j-th bit
    j = 3;
    S &= ~(1 << j);
    print(S);

    // Checking if j-th bit is set
    j = 1;
    int T = (S & (1 << j));
    print(T);   // Non-zero if j-th bit is set. Zero otherwise
    // print(T >> j);   // One if j-th bit is set. Zero otherwise

    // Toggle j-th bit
    j = 3;
    S ^= (1 << j);
    print(S);
    S ^= (1 << j);
    print(S);

    // Get first bit from the right that is set(on)
    T = ((S) & -(S));
    print(T);

    int num_ones = __builtin_popcount(S);
    int leading_zeroes = __builtin_ctz(S);

    cout << num_ones << " " << leading_zeroes << "\n";

    return 0;
}