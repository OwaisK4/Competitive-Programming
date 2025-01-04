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
    vector<int> array(9);       // Odd
    // transform(all(array), array.begin(), [&](auto _){return uid(mt);});

    map<int, int> mp;
    for_each(all(array), [&](int a){mp[a]++;});

    int limit = array.size() / 2;
    for (auto it : mp){
        if (it.second > limit){
            cout << it.first << " appears more than " << limit << " time in given array." << "\n";
        }
    }

    return 0;
}