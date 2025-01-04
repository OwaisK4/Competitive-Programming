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
map<char, vector<char>> mp;
map<char, int> visited;

bool dfs(char str, char target) {
    if (str == target) {
        return true;
    }
    if (!visited.count(str)) {
        visited[str]++;
        for (auto it : mp[str]) {
            bool temp = dfs(it, target);
            // cout << it << " ";
            if (temp) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    fastio;
    string Y, X;
    getline(cin, Y);
    getline(cin, X);

    for (int i = 0; i < Y.size(); i++) {
        if (Y[i] == ' ') {
            continue;
        }
        // mp[X[i]].push_back(Y[i]);
        mp[Y[i]].push_back(X[i]);
    }
    // for (auto it : mp) {
    //     cout << it.first << ": ";
    //     for (auto jt : it.second) {
    //         cout << jt << " ";
    //     }
    //     cout << "\n";
    // }

    string s;
    while (getline(cin, s)) {
        stringstream ss(s);

        vector<string> x;
        string temp;
        while (getline(ss, temp, ' ')) {
            x.push_back(temp);
        }
        string S1 = x.front();
        string S2 = x.back();
        // cout << S1 << " " << S2 << "\n";

        if (S1.length() != S2.length()) {
            cout << "No\n";
            continue;
        }
        if (S1.length() < 3 || S1.length() > 20) {
            cout << "No\n";
            continue;
        }
        bool is_same = true;
        for (int i = 0; i < S1.size(); i++) {
            if (S1[i] != S2[i]) {
                // cout << "S1 = " << S1[i] << "\n";
                // cout << "S2 = " << S2[i] << "\n";
                bool check = dfs(S1[i], S2[i]);
                visited.clear();

                if (!check) {
                    is_same = false;
                    // cout << S1[i] << " and " << S2[i] << " are not same.\n";
                    break;
                }
            }
        }
        if (is_same) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}