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

bool sort_cmp(const pii &a, const pii &b) {
    if (a.first == b.first) {
        if (a.second > b.second) {
            return true;
        }
        return false;
    } else {
        return a.first < b.first;
    }
}

void solve() {
    vector<pii> customers;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, i});
        customers.push_back({b, -i});
    }
    sort(all(customers), sort_cmp);
    int N = customers.size();
    set<int> free_rooms;
    for (int i = 0; i < (int)2e5; i++) {
        free_rooms.insert(i + 1);
    }
    vector<int> room_assigned(n, -1);
    // queue<int> q;
    unordered_map<int, vector<int>> q;
    int cnt = 0, max_cnt = cnt;

    for (int i = 0; i < N; i++) {
        int index = abs(customers[i].second) - 1;
        if (customers[i].second > 0LL) {
            cnt++;
            int room = *free_rooms.begin();
            room_assigned[index] = room;
            q[index].push_back(room);
            free_rooms.erase(room);
        } else {
            cnt--;
            int room = q[index].back();
            q[index].pop_back();
            free_rooms.insert(room);
        }
        max_cnt = max(max_cnt, cnt);
    }
    print(max_cnt);
    print(room_assigned);
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