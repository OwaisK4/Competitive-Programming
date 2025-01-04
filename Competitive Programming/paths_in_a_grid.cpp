#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
using namespace std;
const int N = 5;

template <typename T>
void debug(T *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int sum(int x, int y, int array[][N]) {
    if (x < 0 || y < 0)
        return 0;
    return array[x][y] + max(sum(x, y - 1, array), sum(x - 1, y, array));
}

signed main() {
    int array[N][N] = {
        {3, 7, 9, 2, 7},
        {9, 8, 3, 5, 5},
        {1, 7, 9, 8, 5},
        {3, 8, 6, 4, 10},
        {6, 3, 9, 7, 8}};

    // Recursive Solution
    int answer = sum(N - 1, N - 1, array);
    cout << answer << "\n";

    // Dynamic Programming Solution
    int dp[N + 1][N + 1] = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + array[i - 1][j - 1];
        }
    }
    cout << dp[N][N];
    return 0;
}