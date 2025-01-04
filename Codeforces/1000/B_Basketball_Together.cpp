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

int ceil2(int a, int b) {
    int answer = (a + b - 1) / b;
    return answer;
}

signed main() {
    fastio;
    int N, D;
    cin >> N >> D;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    sort(all(P), greater<int>());
    int n = N;
    int i = 0;
    while (i < N && n > 0) {
        int c = ceil2((D + 1), P[i]);
        if (n < c) {
            break;
        }
        n -= c;
        i++;
    }
    cout << i << "\n";

    return 0;
}