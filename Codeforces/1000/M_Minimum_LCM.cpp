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

int p_lcm(int a, int b) {
    int answer = a / gcd(a, b);
    answer *= b;
    return answer;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = n / i;
                break;
            }
        }
        cout << a << " " << n - a << "\n";
    }

    return 0;
}