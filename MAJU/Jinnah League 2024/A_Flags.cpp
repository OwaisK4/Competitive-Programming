#include <iostream>
#include <numeric>
#include <vector>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

int n;
vvi dp;

int f(int index, int color) {
    if (index == n) {
        return 1;
    }
    if (dp[index][color] != -1) {
        return dp[index][color];
    }
    int answer = 0;
    if (color == 1) {
        answer += f(index + 1, 0);
        answer += f(index + 1, 2);
    } else if (color == 0) {
        answer += f(index + 1, 2);
        if (index + 1 < n) {
            answer += f(index + 2, 2);
        }
    } else {
        answer += f(index + 1, 0);
        if (index + 1 < n) {
            answer += f(index + 2, 0);
        }
    }
    return dp[index][color] = answer;
}

void solve() {
    cin >> n;
    dp.assign(n, vi(3, -1));
    int answer = f(0, 1);
    print(answer);
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}