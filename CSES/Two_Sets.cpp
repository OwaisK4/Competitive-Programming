#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
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

signed main() {
    fastio;
    int n;
    cin >> n;

    int answer = (n * (n + 1)) / 2;
    if (answer % 2 != 0) {
        cout << "NO";
        return 0;
    }
    set<int> s1, s2;
    int k = n;
    int half = answer / 2;
    while (half > 0) {
        if (half - k >= 0) {
            half -= k;
            s1.insert(k);
            k--;
        } else {
            s2.insert(k);
            k--;
        }
    }
    while (k > 0) {
        s2.insert(k);
        k--;
    }
    auto printSet = [](set<int> S) {
        for (auto it : S) {
            cout << it << " ";
        }
        cout << "\n";
    };
    cout << "YES\n";
    print(s1.size());
    printSet(s1);
    print(s2.size());
    printSet(s2);

    return 0;
}