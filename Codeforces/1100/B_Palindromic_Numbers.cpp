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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string num;
        cin >> num;
        vector<int> answer(n + 1);
        for (int i = 0; i < n; i++) {
            answer[i] = '9' - (num[i]);
        }
        if (num[0] != '9') {
            for (int i = 0; i < n; i++) {
                cout << answer[i];
            }
            cout << "\n";
        } else {
            reverse(answer.begin(), answer.end() - 1);
            int value = answer[0] + 2;
            int carry = 0;
            if (value >= 10) {
                carry = 1;
                answer[0] = value % 10;
            } else {
                answer[0] = value;
            }
            for (int i = 1; i < n; i++) {
                value = answer[i] + 1 + carry;
                carry = 0;
                if (value >= 10) {
                    carry = 1;
                    answer[i] = value % 10;
                } else {
                    answer[i] = value;
                }
            }
            answer[n] = carry;
            reverse(answer.begin(), answer.end() - 1);
            for (int i = 0; i < n; i++) {
                cout << answer[i];
            }
            cout << "\n";
        }
    }

    return 0;
}