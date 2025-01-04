#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
using namespace std;

vector<int> tree;
int N;

template <typename T>
void print(vector<T> array){
    for (auto& it : array){
        cout << it << " ";
    }
    cout << "\n";
}

int query(int i){
    // i++;
    int sum = 0;
    while (i > 0){
        sum += tree[i];
        i -= ((i) & (-i));
    }
    return sum;
}

int query(int a, int b){
    return query(b) - query(a - 1);
}

void update(int i, int delta){
    // i++;
    while (i < N){
        tree[i] += delta;
        i += ((i) & (-i));
    }
}

signed main(){
    N = 9;
    vector<int> array = {0, 1, 3, 4, 8, 6, 1, 4, 2};
    tree.assign(N, 0);

    for (int i=1; i<N; i++){
        update(i, array[i]);
    }

    print(array);
    print(tree);

    for (int i=1; i<N; i++){
        cout << query(i) << " ";
    }
    cout << "\n";

    // cout << query(0, 2) << "\n";
    return 0;
}