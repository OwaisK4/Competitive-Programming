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
    int n = 4;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<int>> mirrored;

    for (auto& it : matrix){
        for (auto& jt : it){
            jt = uid(mt);
        }
    }
    cout << "Original matrix\n";
    for_each(all(matrix), [](vector<int> a){print(a);});

    // Mirroring along a random x-axis
    int x = uid(mt) % n;

    int end = n - 1;
    while (end > x){
        mirrored.push_back(matrix[end]);
        end--;
    }

    mirrored.push_back(matrix[x]);

    int start = x - 1;
    while (start >= 0){
        mirrored.push_back(matrix[start]);
        start--;
    }

    cout << "Mirrored matrix at x = " << x << "\n";
    for_each(all(mirrored), [](vector<int> a){print(a);});

    return 0;
}