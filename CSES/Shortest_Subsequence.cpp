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
    map<char, int> mp;
    for (auto &it : s) {
        mp[it]++;
    }
    char min_element = 'Z';
    int min_occurences = LONG_LONG_MAX;
    for (auto &[key, value] : mp) {
        if (value < min_occurences) {
            min_element = key;
            min_occurences = value;
        }
    }
    for (int i = 0; i <= min_occurences; i++) {
        cout << min_element;
    }

    return 0;
}