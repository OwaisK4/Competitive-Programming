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

int partition(vector<int>& array, int l, int r){
    int pivot = array[r];
    int pIndex = l;

    for (int i = l; i < r; i++){
        if (array[i] < pivot){
            swap(array[i], array[pIndex]);
            pIndex++;
        }
    }
    swap(array[r], array[pIndex]);
    return pIndex;
}

void quick_sort(vector<int>& array, int l, int r){
    if (l >= r){
        return;
    }
    int p = partition(array, l, r);
    quick_sort(array, l, p - 1);
    quick_sort(array, p + 1, r);
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

    quick_sort(array, 0, array.size() - 1);
    print(array);

    return 0;
}