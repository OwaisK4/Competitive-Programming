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
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(all(A));

    int i = 0;
    int j = 0;

    bool flag = false;
    while (i < N && j < N) {
        // if (abs(A[j] - A[i]) == abs(X)) {
        if (A[j] - A[i] == X) {
            flag = true;
            break;
        }
        // } else if (abs(A[j] - A[i]) < abs(X)) {
        else if (A[j] - A[i] < X) {
            j++;
        } else {
            i++;
        }
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}