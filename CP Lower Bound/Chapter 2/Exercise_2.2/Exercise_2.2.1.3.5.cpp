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

    int length = 0, max_length = 0;
    for (int i = 0; i < array.size(); i++){
        if (i < array.size() - 1){
            if (array[i] <= array[i+1]){
                length++;
                max_length = max(max_length, length);
            }
            else{
                length++;
                max_length = max(max_length, length);
                length = 0;
            }
        }
        else{
            length++;
            max_length = max(max_length, length);
        }
    }

    cout << "Length of longest increasing subarray: " << max_length << "\n";

    return 0;
}