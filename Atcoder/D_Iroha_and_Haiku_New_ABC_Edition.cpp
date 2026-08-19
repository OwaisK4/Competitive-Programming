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
template <typename T>
void print(T X) {
    cout << X << "\n";
}

signed main() {
    fastio;
    int N, P, Q, R;
    cin >> N >> P >> Q >> R;

    vector<int> A(N), prefix(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    partial_sum(all(A), prefix.begin() + 1);

    for (int i = 0; i < N; i++) {
        int P_rem = P + prefix[i];
        auto it = lower_bound(all(prefix), P_rem);
        if (it != prefix.end() && *it - prefix[i] == P) {
            int j = it - prefix.begin();
            int Q_rem = Q + prefix[j];
            auto jt = lower_bound(all(prefix), Q_rem);
            if (jt != prefix.end() && *jt - prefix[j] == Q) {
                int k = jt - prefix.begin();
                int R_rem = R + prefix[k];
                auto kt = lower_bound(all(prefix), R_rem);
                if (kt != prefix.end() && *kt - prefix[k] == R) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";

    return 0;
}