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

vector<string> board;

signed main() {
    fastio;
    vector<char> ch = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    int n = 8;
    board.resize(n);
    int index = -1;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        if (board[i].find('*', 0) != board[i].npos) {
            index = i;
        }
    }
    int column = board[index].find('*', 0);

    string answer = string(1, ch[column]);
    answer += to_string(n - index);
    cout << answer;

    return 0;
}