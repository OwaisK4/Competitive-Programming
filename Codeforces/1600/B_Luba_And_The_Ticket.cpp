#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

bool isLucky(int n) {
    int left = (n / 1000);
    int right = (n % 1000);

    int leftSum = 0;
    while (left) {
        leftSum += (left % 10);
        left /= 10;
    }
    int rightSum = 0;
    while (right) {
        rightSum += (right % 10);
        right /= 10;
    }

    if (leftSum == rightSum)
        return true;
    else
        return false;
}

signed main() {
    fastio;
    string s;
    cin >> s;
    priority_queue<int, vector<int>, greater<int>> res;
    for (int i = 0; i <= 999999; i++) {
        if (isLucky(i)) {
            int cnt = 0;
            string current = to_string(i);
            while (current.size() < s.size()) {
                current.insert(current.begin(), '0');
            }
            for (int j = 0; j < current.size(); j++) {
                if (s[j] != current[j])
                    cnt++;
            }
            res.push(cnt);
            // cout << current << "\n";
        }
    }
    // while (!res.empty()) {
    //     cout << res.top() << "\n";
    //     res.pop();
    // }
    cout << res.top();

    return 0;
}