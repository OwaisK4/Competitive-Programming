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
    uniform_int_distribution<int> uid(0, 100);
    int N = 10;
    unordered_set<int> s;
    while (s.size() < N){
        s.insert(uid(mt));
    }
    vector<int> array(all(s));
    print(array);

    nth_element(array.begin(), array.begin() + (N / 2), array.end());
    // sort(all(array));
    print(array);
}