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
    vector<vector<int>> matrix(4, vector<int>(4));
    vector<vector<int>> transposed(4, vector<int>(4));

    for (auto& it : matrix){
        for (auto& jt : it){
            jt = uid(mt);
        }
    }
    cout << "Original matrix\n";
    for_each(all(matrix), [](vector<int> a){print(a);});


    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix.size(); j++){
            transposed[i][j] = matrix[j][i];
        }
    }

    cout << "Transposed matrix\n";
    for_each(all(transposed), [](vector<int> a){print(a);});

    return 0;
}