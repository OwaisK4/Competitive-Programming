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

    int k = 5;

    sort(all(array));
    int n = array.size();
    for (int i = 0, j = n-1; i < j;){
        if ((array[i] + array[j]) == k){
            cout << array[i] << " + " << array[j] << " = " << k << "\n";
            i++;
            j--;
        }
        else if ((array[i] + array[j]) < k){
            i++;
        }
        else{
            j--;
        }
    }

    return 0;
}