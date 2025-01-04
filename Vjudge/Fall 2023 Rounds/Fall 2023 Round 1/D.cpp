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
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int H, W;
    cin >> H >> W;
    vector<vector<char>> c(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c[i][j];
        }
    }
    int count = 0;
    if (H % 2 != 0) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if ((j + 1) < W && c[i][j] == c[i][j + 1] && c[i][j] != '0') {
                    count += 2;
                    c[i][j] = '0';
                    c[i][j + 1] = '0';
                    j++;
                }
            }
        }
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                if ((j + 1) < H && c[j][i] == c[j + 1][i] && c[j][i] != '0') {
                    count += 2;
                    c[j][i] = '0';
                    c[j + 1][i] = '0';
                    j++;
                }
            }
        }
    } else {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                if ((j + 1) < H && c[j][i] == c[j + 1][i] && c[j][i] != '0') {
                    count += 2;
                    c[j][i] = '0';
                    c[j + 1][i] = '0';
                    j++;
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if ((j + 1) < W && c[i][j] == c[i][j + 1] && c[i][j] != '0') {
                    count += 2;
                    c[i][j] = '0';
                    c[i][j + 1] = '0';
                    j++;
                }
            }
        }
    }
    int answer = (H * W) - count;
    cout << answer;

    return 0;
}