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

void count_sort(vector<int>& array, int n, int l, int r){
    int k = r - l + 1;
    vector<int> f(k, 0);
    for (int i = 0; i < k; i++){
        f[array[i] - l]++;
    }

    partial_sum(all(f), f.begin());

    vector<int> output(n);
    for (int i = n-1; i >= 0; i--){
        output[f[array[i] - l] - 1] = array[i];
        f[array[i] - l]--;
    }

    print(output);
}


signed main(){
    mt19937 mt(seed);
    uniform_int_distribution<int> uid(0, 9);
    int n = 10;
    vector<int> array(n);    
    for (auto& it : array){
        it = uid(mt);
    }
    cout << "Original array\n";
    print(array);

    auto [it1, it2] = minmax_element(all(array));
    int l = *it1;
    int r = *it2;

    // cout << "L = " << l << "\n";
    // cout << "R = " << r << "\n";

    count_sort(array, n, l, r);

    // print(array);

    return 0;
}