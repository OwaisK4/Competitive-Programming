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
    // file_read("gymnastics.in");
    // file_write("gymnastics.out");

    int K, N;
    cin >> K >> N;
    vector<int> minimum(N, LONG_LONG_MAX);
    vector<int> maximum(N, LONG_LONG_MIN);
    int performance;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> performance;
            performance--;
            minimum[performance] = min(minimum[performance], j);
            maximum[performance] = max(maximum[performance], j);
            // minimum[j] = min(minimum[j], performance);
            // maximum[j] = max(maximum[j], performance);
        }
    }
    print(minimum);
    print(maximum);
    int consistent = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (maximum[i] < minimum[j]) {
                consistent++;
            }
        }
    }
    cout << consistent;

    return 0;
}