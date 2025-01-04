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

signed main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string answer;
        cin >> answer;
        map<char, vector<int>> mp;
        for (int i = 0; i < (int)s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        bool flag = true;
        char a = answer[answer.size() - 1];
        if (mp[a].empty()) {
            cout << "NO\n";
            continue;
        }
        int index = mp[a].back();
        mp[a].pop_back();
        for (int i = answer.size() - 2; i >= 0; i--) {
            a = answer[i];
            if (mp[a].empty() || mp[a].back() > index) {
                flag = false;
                break;
            }
            // cout << "Index = " << index << "\n";
            // cout << "mp[a].back() = " << mp[a].back() << "\n";

            index = mp[a].back();
            mp[a].pop_back();
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}