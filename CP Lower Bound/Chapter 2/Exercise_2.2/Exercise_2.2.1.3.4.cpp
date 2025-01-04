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
    uniform_int_distribution<int> uid(0, 9);
    vector<int> array(10);
    transform(all(array), array.begin(), [&](auto _){return uid(mt);});
    print(array);

    sort(all(array));

    vector<long long>::iterator start = lower_bound(all(array), 3);
    vector<long long>::iterator end = upper_bound(all(array), 7);

    for (auto it = start; it != end; it++){
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}