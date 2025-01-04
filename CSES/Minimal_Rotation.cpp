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
    string s;
    cin >> s;
    int n = s.size();
    int max_index = 0;
    int max_element = 'a';
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > max_element) {
            max_index = i;
            max_element = s[i];
        }
    }
    string answer;
    for (int i = max_index + 1; i < n; i++) {
        answer += s[i];
    }
    for (int i = 0; i <= max_index; i++) {
        answer += s[i];
    }
    cout << answer;

    return 0;
}