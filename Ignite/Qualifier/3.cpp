#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
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

vi dec_to_binary(int n) {
    vi bin;
    while (n) {
        if (n & 1) {
            bin.push_back(1);
        } else {
            bin.push_back(0);
        }
        n /= 2;
    }
    reverse(all(bin));
    return bin;
}

int bin_to_dec(vi con) {
    int dec = 0;
    int i = 0;
    reverse(all(con));
    for (auto it : con) {
        dec += (pow(2, i) * it);
        i++;
    }
    return dec;
}

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

vi converted;

void printInorder(Node *&r) {
    if (r == nullptr) {
        return;
    }
    printInorder(r->left);
    // cout << r->data << " ";
    converted.push_back(r->data);
    printInorder(r->right);
}

void solve() {
    int n;
    cin >> n;
    vi bin = dec_to_binary(n);
    // print(bin);
    Node *head = new Node(bin[0]);
    Node *r = head;
    bin.erase(bin.begin());
    for (auto it : bin) {
        if (it == 0) {
            r->left = new Node(it);
            r = r->left;
        } else {
            r->right = new Node(it);
            r = r->right;
        }
    }
    // print(r->data);
    printInorder(head);
    // print("");
    int answer = bin_to_dec(converted);
    print(answer);
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