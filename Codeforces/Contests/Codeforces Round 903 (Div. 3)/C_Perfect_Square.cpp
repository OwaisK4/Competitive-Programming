#include <bits/stdc++.h>
#include <ext/numeric>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> matrix(n, vector<char>(n));
        vector<vector<char>> rotated(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // rotated[n - i - 1][j] = matrix[i][j];
                rotated[n - j - 1][i] = matrix[i][j];
                // rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rotated[i][j] || matrix[i][j] == 'z' || rotated[i][j] == 'z') {
                    continue;
                }
                total += (max(matrix[i][j], rotated[i][j]) - min(matrix[i][j], rotated[i][j]));
                // rotated[i][j] = '$';
            }
        }
        cout << total << "\n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << rotated[i][j];
        //     }
        //     cout << "\n";
        // }
    }

    return 0;
}