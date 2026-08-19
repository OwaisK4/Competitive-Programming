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
using pii = pair<int, int>;

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

int fact(int x) {
    int answer = 1;
    for (int i = 1; i <= x; i++) {
        answer *= i;
    }
    return answer;
}

int solve(string &s) {
    map<char, int> mp;
    for (auto it : s) {
        mp[it]++;
    }
    int answer = fact(s.size());
    for (auto it : mp) {
        answer /= fact(it.second);
    }
    return answer;
}

signed main() {
    fastio;
    string s;
    cin >> s;
    sort(all(s));
    cout << solve(s) << "\n";
    set<string> result;
    do {
        // print(s);
        result.insert(s);
    } while (next_permutation(all(s)));
    for (auto it : result) {
        print(it);
    }

    // vector<string> sorted(all(result));
    // sort(all(sorted));
    // for (auto it : sorted) {
    //     print(it);
    // }

    return 0;
}