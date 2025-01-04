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
    mt19937 mt(seed);
    uniform_int_distribution uid(0, 9);
    int n = 10;
    vector<int> array(n);    
    for (auto& it : array){
        it = uid(mt);
    }
    cout << "Original array\n";
    print(array);

    map<int, int> mp;
    for (auto& it : array){
        mp[it]++;
    }

    for (auto & [key, value] : mp){
        cout << key << " " << value << "\n";
    }

    // print(array);

    return 0;
}