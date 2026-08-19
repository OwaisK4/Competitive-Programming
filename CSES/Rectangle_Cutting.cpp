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

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int f(int a, int b) {
    if (a == b || a == 0 || b == 0) {
        return 0;
    }
    int minimum = min(a, b);
    int answer;
    if (minimum == a) {
        for (int i = 1; i < b; i++) {
            answer = min(answer, f(a, i) + f(a, b - i) + 1);
        }
    } else {
        for (int i = 1; i < a; i++) {
            answer = min(answer, f(i, b) + f(a - i, b) + 1);
        }
    }
    return answer;
}

signed main() {
    fastio;
    int a, b;
    cin >> a >> b;

    int answer = f(a, b);
    cout << answer;

    return 0;
}