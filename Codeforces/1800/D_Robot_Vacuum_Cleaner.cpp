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

bool cmp(string s1, string s2) {
    double ratio1 = count(all(s1), 's') / (double)s1.size();
    double ratio2 = count(all(s2), 's') / (double)s2.size();
    return ratio1 > ratio2;
}

signed main() {
    fastio;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(all(s), cmp);
    // print(s);

    string combined = "";
    for (auto &it : s) {
        combined += it;
    }
    // cout << combined;
    int k = combined.size();

    vector<int> suffix(k + 1, 0);
    for (int i = k - 1; i >= 0; i--) {
        if (combined[i] == 'h')
            suffix[i] = suffix[i + 1] + 1;
        else
            suffix[i] = suffix[i + 1];
    }
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (combined[i] == 's') {
            cnt += suffix[i + 1];
        }
    }
    cout << cnt;

    return 0;
}