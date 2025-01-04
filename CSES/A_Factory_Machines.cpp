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

vector<int> machines;

bool produce(int t, int x) {
    int total = 0;
    for (auto it : machines) {
        total += (t / it);
    }
    if (total >= x) {
        return true;
    } else {
        return false;
    }
}

int first_true(int low, int high, int target) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (produce(mid, target)) {
            high = mid;
        } else {
            low = mid + 1;
        }
        // cout << high << " ";
    }
    return high;
}

signed main() {
    fastio;
    int n, t;
    cin >> n >> t;
    machines.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    int upper_limit = *min_element(all(machines));
    upper_limit *= t;
    int answer = first_true(1, upper_limit, t);
    cout << answer;

    return 0;
}