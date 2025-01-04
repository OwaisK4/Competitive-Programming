#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

vector<int> coins = {1, 2, 3, 4, 5};

int calculate_sum(int sum, int last, int N) {
    if (sum == N) {
        return 1;
    }
    if (sum > N) {
        return 0;
    }
    int answer = 0;
    for (auto it : coins) {
        if (it >= last) {
            answer += calculate_sum(sum + it, it, N);
        }
    }
    return answer;
}

signed main() {
    fastio;
    int N = 10;
    int answer = 0;

    cout << calculate_sum(0, 0, N) << "\n";

    return 0;
}