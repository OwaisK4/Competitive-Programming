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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    deque<int> d;
    int curr_sum = 0;
    int max_sum = 0;
    int i;
    for (i = 0; i < a; i++) {
        d.push_back(x[i]);
        curr_sum += x[i];
    }
    max_sum = curr_sum;
    while (i <= n) {
        // cout << curr_sum << " ";
        while (d.front() <= 0 && d.size() > a) {
            curr_sum -= d.front();
            d.pop_front();
            max_sum = max(max_sum, curr_sum);
        }
        if (i == n) {
            break;
        }
        if (d.size() == b) {
            curr_sum -= d.front();
            d.pop_front();
            if (d.size() >= a)
                max_sum = max(max_sum, curr_sum);
            curr_sum += x[i];
            d.push_back(x[i]);
            max_sum = max(max_sum, curr_sum);
        } else {
            curr_sum += x[i];
            d.push_back(x[i]);
            max_sum = max(max_sum, curr_sum);
        }
        i++;
    }
    cout << max_sum;

    return 0;
}

// if (curr_sum < x[i]) {
//     d.clear();
//     curr_sum = 0;
//     for (int j = 0; j < a && (j + i) < n; j++) {
//         d.push_back(x[j + i]);
//         curr_sum += x[j + i];
//     }
//     if (d.size() == a) {
//         max_sum = max(max_sum, curr_sum);
//     }
// } else if (d.size() == b) {