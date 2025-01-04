#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using pii = pair<int, int>;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

void print_subsets(vector<int> &a) {
    int n = a.size();
    int limit = 1 << n;
    vector<int> subset;
    for (int i = 0; i <= limit; i++) {
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                subset.push_back(a[j]);
            }
        }
        print(subset);
        subset.clear();
    }
}

signed main() {
    fastio;
    mt19937 mt((random_device())());
    vector<int> a;
    uniform_int_distribution<int> uid(0, 9);
    for (int i = 0; i < 3; i++) {
        a.push_back(uid(mt));
    }
    // print(a);
    print_subsets(a);

    return 0;
}