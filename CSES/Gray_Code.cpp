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

set<string> ss;
vector<string> answer;

void generate(string s, int index) {
    if (index < 0) {
        return;
    }
    if (ss.find(s) == ss.end()) {
        answer.push_back(s);
        ss.insert(s);
    }
    // print(s);
    if (s[index] == '0') {
        s[index] = '1';
        generate(s, index);
        s[index] = '0';
    }
    generate(s, index - 1);
}

void solve() {
    int n;
    cin >> n;
    vector<string> gray = {"0", "1"};
    for (int i = 0; i < n - 1; i++) {
        vector<string> temp;
        for (int j = 0; j < gray.size(); j++) {
            temp.push_back("0" + gray[j]);
        }
        for (int j = gray.size() - 1; j >= 0; j--) {
            temp.push_back("1" + gray[j]);
        }
        gray = temp;
    }

    for (auto it : gray) {
        print(it);
    }
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}