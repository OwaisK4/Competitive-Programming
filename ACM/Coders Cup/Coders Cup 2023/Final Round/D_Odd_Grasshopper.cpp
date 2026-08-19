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
        int x, n;
        cin >> x >> n;

        int mul_4 = n;
        while (mul_4 % 4 != 0) {
            mul_4++;
        }

        int rem = mul_4 - n;
        if (rem == 0) {
            cout << x << "\n";
            continue;
        } else if (x % 2 == 0) {
            if (rem > 0) {
                rem--;
                x += mul_4;
            }
            if (rem > 0) {
                rem--;
                x -= (mul_4 - 1);
            }
            if (rem > 0) {
                rem--;
                x -= (mul_4 - 2);
            }
        } else {
            if (rem > 0) {
                rem--;
                x -= mul_4;
            }
            if (rem > 0) {
                rem--;
                x += (mul_4 - 1);
            }
            if (rem > 0) {
                rem--;
                x += (mul_4 - 2);
            }
        }
        cout << x << "\n";
    }

    return 0;
}