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
        print(array[i]);
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

struct Ring {
public:
    int a, b, h;
    bool operator<(const Ring &other) {
        // return this->b > other.b;
        if (this->b > other.b) {
            return true;
        } else if (this->b < other.b) {
            return false;
        } else {
            if (this->a > other.a) {
                return true;
            }
        }
    }
};

ostream &operator<<(ostream &out, const Ring &r) {
    out << r.a << " " << r.b << " " << r.h;
    return out;
}

void solve() {
    int n;
    cin >> n;
    vector<Ring> rings(n);
    for (int i = 0; i < n; i++) {
        cin >> rings[i].a >> rings[i].b >> rings[i].h;
    }
    sort(all(rings));
    print(rings);
    int cnt = rings[0].h;
    int maximum = cnt;
    for (int i = 1; i < n; i++) {
        if (rings[i].b <= rings[i - 1].a) {
            cnt = 0;
        }
        cnt += rings[i].h;
        maximum = max(maximum, cnt);
    }
    cout << maximum;
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