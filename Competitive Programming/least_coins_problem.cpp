#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

template <typename T>
void debug(T *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

const int N = 1000000;
bool ready[N] = {};
int value[N] = {};

int solve(int x, vector<int> coins) {
    if (x == 0)
        return 0;
    else if (x < 0)
        return LONG_LONG_MAX - 1;
    else if (ready[x])
        return value[x];
    int best = LONG_LONG_MAX - 1;
    for (auto c : coins) {
        best = min(best, solve(x - c, coins) + 1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}

signed main() {
    vector<int> coins = {1, 5, 7};
    int x = 11;
    // for (int i = 0; i <= 10; i++) {
    cout << solve(x, coins) << "\n";
    // }
    for (int i = 0; i < x + 1; i++) {
        cout << value[i] << " ";
    }
    cout << endl;

    return 0;
}