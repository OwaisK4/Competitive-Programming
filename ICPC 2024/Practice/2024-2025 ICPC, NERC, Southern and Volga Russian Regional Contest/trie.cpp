#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

class Trie {
public:
    Trie *child[26];
    bool worldEnd;
    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        worldEnd = false;
    }
};

void insert(Trie *root, string s) {
    int n = s.size();
    Trie *current = root;
    for (int i = 0; i < n; i++) {
        if (current->child[s[i] - 'a'] == nullptr) {
            current->child[s[i] - 'a'] = new Trie();
        }
        current = current->child[s[i] - 'a'];
    }
    current->worldEnd = true;
}
bool search(Trie *root, string s) {
    int n = s.size();
    Trie *current = root;
    for (int i = 0; i < n; i++) {
        if (current->child[s[i] - 'a'] == nullptr) {
            return false;
        }
        current = current->child[s[i] - 'a'];
    }
    return current->worldEnd;
}

void solve() {
    Trie *root = new Trie();
    vector<string> arr =
        {"and", "ant", "do", "geek", "dad", "ball"};
    for (const string &s : arr) {
        insert(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (search(root, s))
            cout << "Present\n";
        else
            cout << "Not Present\n";
    }
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}