#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

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

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (auto &c : s) {
            freq[c - 'a']++;
        }

        auto maximum = max_element(all(freq));
        auto minimum = min_element(all(freq));
        int max_char = maximum - freq.begin();

        int others = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' != max_char) {
                others++;
            }
        }

        int max_elem = *maximum;

        int answer = max_elem - others;
        if (answer < 0) {
        }

        cout << answer << "\n";
    }

    return 0;
}