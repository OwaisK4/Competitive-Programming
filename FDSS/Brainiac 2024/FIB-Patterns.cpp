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

vector<int> fibonacci(101, 0);

void solve() {
    int n;
    cin >> n;
    vector<int> p_vector;
    string p;
    cin.ignore();
    getline(cin, p);
    stringstream ss(p);
    char temp;
    while (ss >> temp) {
        p_vector.push_back(temp - '0');
    }

    vector<int> fib(1, 0);
    if (n <= 2) {
        if (n == 0 || n == 1) {
            fib.resize(1);
            fib[0] = n;
        } else {
            fib.resize(2);
            fib[0] = 1;
            fib[1] = 0;
        }
    } else {
        fib.resize(2);
        fib[0] = 1;
        fib[1] = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < fibonacci[i]; j++) {
                fib.push_back(fib[j]);
            }
        }
    }
    int count = 0;

    for (int i = 0; i < (int)fib.size(); i++) {
        bool valid = true;
        for (int j = 0; j < (int)p_vector.size(); j++) {
            if (i + j >= (int)fib.size()) {
                valid = false;
                break;
            }
            if (fib[i + j] != p_vector[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count += 1;
        }
    }
    cout << count;
    // print(fib);
}

signed main() {
    fastio;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= 100; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}