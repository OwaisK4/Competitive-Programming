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
    int N;
    cin >> N;
    vector<int> a(N);
    set<int> s;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(all(a));
    int dups = 0;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] == a[i + 1]) {
            dups++;
        }
    }

    int answer = 1;
    auto it = s.begin();
    while (it != s.end()) {
        if (*it == answer) {
            answer++;
            it = next(it);
        } else {
            if (dups > 1) {
                dups -= 2;
                answer++;
            }
            if (it != s.end() && next(it) != s.end() && dups > 0) {
                dups--;
                s.erase(s.end());
                answer++;
            } else if (it != s.end() && next(it) != s.end() && next(next(it)) != s.end()) {
                s.erase(s.end());
                s.erase(s.end());
                answer++;
            } else {
                break;
            }
        }
    }
    if (dups > 0) {
        answer += (dups / 2);
    }
    cout << answer - 1;

    // vector<int> clean(all(s));
    // print(clean);
    // int i = 0;
    // int j = clean.size() - 1;
    // int counter = 1;
    // while (i < clean.size()) {
    //     if (clean[i] == counter) {
    //         i++;
    //         counter++;
    //     } else {
    //         if (dups > 1) {
    //             dups -= 2;
    //             counter++;
    //         } else if (j > i) {
    //             if (dups == 1 && j > i) {
    //                 j--;
    //                 dups--;
    //                 counter++;
    //             } else if (j > i + 1) {
    //                 j -= 2;
    //                 counter++;
    //             } else {
    //                 break;
    //             }
    //         } else if (dups == 1 && j == i) {
    //             j--;
    //             dups--;
    //             counter++;
    //             break;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // if (dups) {
    //     counter += (dups / 2);
    // }
    // cout << counter - 1;

    return 0;
}