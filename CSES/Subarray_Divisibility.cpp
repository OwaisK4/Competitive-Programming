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

    vector<long long> M(N);
    long long psums = 0;
    M[psums] = 1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        psums += a;
        // Remember to account for negative sums
        M[(psums % N + N) % N]++;
        // M[psums % N]++;
    }

    long long ans = 0;
    for (long long x : M) {
        /*
         * Calculating the # of pairs.
         * This calculates the pairs without
         * duplicates and reverse groups.
         */
        ans += x * (x - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}