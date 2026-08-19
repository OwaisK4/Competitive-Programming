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
    int N;
    cin >> N;
    string S;
    cin >> S;

    int a = S.find("MM", 0);
    int b = S.find("FF", 0);
    if (a != S.npos || b != S.npos) {
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}