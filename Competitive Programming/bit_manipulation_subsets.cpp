#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

void subsets(vector<int> array, int n, int target){
    chrono::time_point start = chrono::high_resolution_clock::now();
    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        vector<int> subset;
        for (int j = 0; j < n; j++){
            if (i & (1 << j)){
                sum += array[j];
                subset.push_back(array[j]);
            }
        }
        if (sum == target){
            print(subset);
        }
    }
    chrono::time_point end = chrono::high_resolution_clock::now();
    chrono::duration elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Elapsed seconds = " << elapsed.count() << "\n";
}

signed main(){
    vector<int> array = {1, 2, 3, 4, 5, 6};
    int n = array.size();
    int target = 7;
    subsets(array, n, target);

    return 0;
}