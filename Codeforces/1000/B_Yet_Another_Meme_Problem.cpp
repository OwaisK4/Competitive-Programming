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

template <class T>
int numDigits(T number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
        int length = numDigits(B);
        string mul_9 = string(length, '9');
        int n = stoll(mul_9);
        if (n > B) {
            length--;
        }
        int answer = A * length;
        cout << answer << "\n";
    }
    // int A = 50, B = 100;
    // vector<tuple<int, int, int>> results;
    // for (int i = 1; i <= A; i++) {
    //     for (int j = 1; j <= B; j++) {
    //         int answer = (i * j) + i + j;
    //         int conc = stoi(to_string(i) + to_string(j));
    //         if (answer == conc) {
    //             results.push_back({i, j, conc});
    //         }
    //     }
    // }
    // for (auto &it : results) {
    //     cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << "\n";
    // }

    return 0;
}