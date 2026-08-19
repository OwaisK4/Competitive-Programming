#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

vector<int> first_op(vector<int> a, int n){
    for (int i=0; i<(2*n)-1; i+=2){
        swap(a[i+1], a[i]);
    }
    return a;
}
vector<int> second_op(vector<int> a, int n){
    for (int i=0; i<n; i++){
        swap(a[i], a[i+n]);
    }
    return a;
}

signed main(){
    fastio;
    int n;
    cin >> n;

    int size = 2*n;
    vector<int> a(size, 0);
    for (int i=0; i<size; i++){
        cin >> a[i];
    }
    vector<int> original(all(a));

    if (is_sorted(all(a))){
        cout << 0;
        return 0;
    }

    int count = 0;
    int min_count;
    for (int i=0; i<size; i++){
        a = first_op(a, n);
        count++;
        if (is_sorted(all(a))){
            break;
        }
        a = second_op(a, n);
        count++;
        if (is_sorted(all(a))){
            break;
        }
    }

    min_count = count;
    count = 0;
    a = original;

    for (int i=0; i<size; i++){
        a = second_op(a, n);
        count++;
        if (is_sorted(all(a))){
            break;
        }

        a = first_op(a, n);
        count++;
        if (is_sorted(all(a))){
            break;
        }
    }
    min_count = min(min_count, count);
    cout << ((min_count > size)? -1: min_count);

    return 0;
}