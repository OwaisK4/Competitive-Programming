#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int modpow(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    }
    int answer = modpow(x, n / 2);
    answer *= answer;
    if (n % 2) {
        answer *= x;
    }
    return answer;
}

bool is_RC(string &s) {
    int R_index = 0;
    int C_index = s.find('C', 0);
    if (s[R_index] != 'R' || s[C_index] != 'C') {
        return false;
    }
    if (abs(R_index - C_index) < 2) {
        return false;
    }
    for (int i = R_index + 1; i < C_index; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    if (is_RC(s)) {
        int R_index = 0;
        int C_index = s.find('C', 0);
        int rows = stoll(s.substr(1, C_index - R_index - 1));
        int columns = stoll(s.substr(C_index + 1, s.size() - C_index - 1));

        string letters = "";
        while (columns > 0) {
            int mod = columns % 26;
            if (mod == 0) {
                columns -= 26;
                letters += 'Z';
            } else {
                letters += ('A' + mod - 1);
            }
            columns /= 26;
        }
        reverse(all(letters));
        string answer = letters + to_string(rows);
        cout << answer << "\n";
    } else {
        string letters = "";
        for (int i = 0; i < s.size() && (s[i] >= 'A' && s[i] <= 'Z'); i++) {
            letters += s[i];
        }
        string numbers = "";
        for (int i = letters.size(); i < s.size(); i++) {
            numbers += s[i];
        }
        int columns = 0;
        for (int i = letters.size() - 1; i >= 0; i--) {
            int value = letters[i] - 'A' + 1;
            value = value * modpow(26, letters.size() - i - 1);
            columns += value;
        }

        int rows = stoll(numbers);
        string answer = "R" + to_string(rows) + "C" + to_string(columns);
        cout << answer << "\n";
    }
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}