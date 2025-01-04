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

void merge(vector<int>& array, int l, int m, int r){
    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;   // r - (m + 1) + 1, to be precise
    vector<int> L(n1), R(n2);

    for (i=0; i<n1; i++){
        L[i] = array[l + i];
    }
    for (j=0; j<n2; j++){
        R[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& array, int l, int r){
    if (l >= r){
        return;
    }
    int m = (l + r) / 2;        // l + (r - l)/2 to prevent overflow
    merge_sort(array, l, m);
    merge_sort(array, m + 1, r);
    merge(array, l, m, r);
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

    merge_sort(array, 0, array.size() - 1);
    print(array);

    return 0;
}