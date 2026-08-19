#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
ios::sync_with_stdio(false); \
cin.tie(0);                  \
cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
    cout << array[i] << " ";
}
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

vector<int> S = {
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    47,
    53,
    59,
    67,
    71,
    83,
    89,
    101,
    107,
    109,
    113,
    127,
    131,
    137,
    139,
    149,
    157,
    167,
    179,
    181,
    191,
    197,
    199,
    211,
    227,
    233,
    239,
    251,
    257,
    263,
    269,
    281,
    293,
    307,
    311,
    317,
    337,
    347,
    353,
    359,
    379,
    389,
    401,
    409,
    419,
    431,
    443,
    449,
    461,
    467,
    479,
    487,
    491,
    499,
    503,
    509,
    521,
    541,
    557,
    563,
    569,
    571};

void solve() {
    int n;
    cin >> n;
    int i = 0;
    vector<int> facs;
    while (i < S.size() && S[i] < n){
        while (((n % S[i]) == 0) && n >= S[i]){
            facs.push_back(S[i]);
            n = n / S[i];
        }
        i++;
    }
    print(facs);
}

void solveAll() {
    int n;
    cin >> n;
    n = 500;
    int max_i = 0, max_j = 0;
    int totalPoints = 0;
    for (int j = 2; j < n; j++) {
        int k = j;
        int i = 0;
        vector<int> facs;
        while (i < S.size() && S[i] < k){
            while (((k % S[i]) == 0) && k >= S[i]){
                facs.push_back(S[i]);
                k = k / S[i];
            }
            i++;
        }
        if (max_j < facs.size()){
            max_j = facs.size();
            max_i = j;
        }
        // cout << j << ", " << facs.size() << "\n";
        totalPoints += facs.size();
    }
    cout << "Maximum = " << max_i << ": " << max_j <<"\n";
    cout << "Total points = " << totalPoints <<"\n";
}

signed main() {
    // fastio;
    
    vector<bool> prime(2e7 + 1, true);
    prime[0] = prime[1] = false;
    int n = 2e6 + 1;
    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    int t = 1;
    // cin >> t;
    while (t--) {
        solveAll();
    }

    return 0;
}