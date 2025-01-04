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
        map<int, int> mp;

        for (auto &c : s) {
            freq[c - 'a']++;
        }
        sort(all(freq), greater<int>());

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                mp[i] = freq[i];
            }
        }
        while (mp.size() > 1) {
            auto it = mp.begin();
            for (auto jt = next(it); jt != mp.end();) {
                auto temp = next(jt);
                it->second--;
                jt->second--;
                if (jt->second <= 0) {
                    mp.erase(jt);
                }
                if (it->second <= 0) {
                    mp.erase(it);
                    break;
                }
                jt = temp;
            }
        }
        // for (auto it : mp) {
        //     cout << it.second << " ";
        // }
        // cout << "\n";
        if (mp.size() == 0) {
            cout << 0 << "\n";
        } else {
            cout << mp.begin()->second << "\n";
        }
    }

    return 0;
}

// while (freq.size() > 1) {
//     int i = 0;
//     for (int j = i + 1; j < n; j++) {
//         if (freq[i] > 0 && freq[j] > 0) {
//             freq[i]--;
//             freq[j]--;
//         }
//         if (freq[i] <= 0) {
//             break;
//         }
//     }
//     sort(all(freq), greater<int>());
//     while (!freq.empty() && freq[freq.size() - 1] == 0) {
//         freq.pop_back();
//     }
// }
// cout << freq[0] << "\n";