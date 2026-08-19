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
    int N;
    cin >> N;
    vector<int> G, L;
    for (int i = 0; i < N; i++) {
        char dir;
        int index;
        cin >> dir >> index;
        if (dir == 'G') {
            G.push_back(index);
        } else {
            L.push_back(index);
        }
    }
    vector<int> positions = G;
    positions.insert(positions.end(), all(L));
    // print(positions);

    int min_dist = LONG_LONG_MAX;
    for (auto it : positions) {
        int current = 0;
        for (auto jt : G) {
            if (jt > it) {
                current++;
            }
        }
        for (auto jt : L) {
            if (jt < it) {
                current++;
            }
        }
        min_dist = min(min_dist, current);
    }
    cout << min_dist;

    return 0;
}