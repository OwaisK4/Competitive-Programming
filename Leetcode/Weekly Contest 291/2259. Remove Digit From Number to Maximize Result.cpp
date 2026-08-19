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

void solve() {
    string number = "15454";
    // cin >> number;

    char digit = '4';

    int l_index = -1;
    for (int i = 0; i < number.size() - 1; i++) {
        if (number[i] == digit && number[i + 1] > digit) {
            l_index = i;
            break;
        }
    }
    // if (number[0] == digit && number[1] > digit) {
    //     l_index = 0;
    // }
    int r_index = number.rfind(digit, number.size());
    cout << l_index << " " << r_index << "\n";
    if (l_index != -1) {
        number.erase(l_index, 1);
    } else {
        number.erase(r_index, 1);
    }
    for (int i = 0; i < number.size(); i++) {
        cout << number[i];
    }
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}