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
    int M;
    cin >> M;
    vector<int> D(M);
    int sum = 1;
    for (int i = 0; i < M; i++) {
        cin >> D[i];
        sum += D[i];
    }
    int mid = sum / 2;
    int i = 0;
    while (i < M && (mid - D[i]) > 0) {
        mid -= D[i];
        i++;
    }
    cout << i + 1 << " " << mid;

    return 0;
}