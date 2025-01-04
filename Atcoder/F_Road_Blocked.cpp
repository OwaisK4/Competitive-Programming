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

int N, M, Q;
vector<vector<int>> graph;
// map<int, bool> blocked;

void floyd_warshall() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // if (blocked[i] || blocked[j] || blocked[k] || graph[i][k] == LONG_LONG_MAX || graph[k][j] == LONG_LONG_MAX)
                if (graph[i][k] == LONG_LONG_MAX || graph[k][j] == LONG_LONG_MAX)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
// void floyd_warshall(int K) {
//     for (int k = 0; k < N; k++) {
//         if (k == K) {
//             continue;
//         }
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 // if (blocked[i] || blocked[j] || blocked[k] || graph[i][k] == LONG_LONG_MAX || graph[k][j] == LONG_LONG_MAX)
//                 if (graph[i][k] == LONG_LONG_MAX || graph[k][j] == LONG_LONG_MAX)
//                     continue;
//                 graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
//             }
//         }
//     }
// }

void solve() {
    cin >> N >> M >> Q;
    graph.assign(N, vector<int>(N, LONG_LONG_MAX));
    for (int i = 0; i < N; i++) {
        graph[i][i] = 0;
    }
    vector<array<int, 3>> roads;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        roads.push_back({A, B, C});
        graph[A][B] = C;
        graph[B][A] = C;
    }

    vector<array<int, 3>> ops;
    for (int i = 0; i < Q; i++) {
        int t, a, b;
        cin >> t;
        if (t == 1) {
            cin >> b;
            b--;
            // blocked[b] = true;
            auto road = roads[b];
            graph[road[0]][road[1]] = LONG_LONG_MAX;
            graph[road[1]][road[0]] = LONG_LONG_MAX;
            ops.push_back({1, b, -1});
        } else {
            cin >> a >> b;
            a--;
            b--;
            ops.push_back({2, a, b});
        }
    }
    floyd_warshall();
    reverse(all(ops));
    vector<int> answers;
    for (int i = 0; i < ops.size(); i++) {
        auto op = ops[i];
        if (op[0] == 1) {
            auto road = roads[op[1]];
            int A = road[0], B = road[1], C = road[2];
            graph[A][B] = min(graph[A][B], C);
            graph[B][A] = min(graph[B][A], C);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (graph[i][A] != LONG_LONG_MAX && graph[B][j] != LONG_LONG_MAX)
                        graph[i][j] = min(graph[i][j], graph[i][A] + graph[A][B] + graph[B][j]);
                    if (graph[i][B] != LONG_LONG_MAX && graph[A][j] != LONG_LONG_MAX)
                        graph[i][j] = min(graph[i][j], graph[i][B] + graph[B][A] + graph[A][j]);
                }
            }
        } else {
            int A = op[1], B = op[2];
            if (graph[A][B] == LONG_LONG_MAX) {
                answers.push_back(-1);
            } else {
                answers.push_back(graph[A][B]);
            }
        }
    }
    reverse(all(answers));
    for (auto it : answers) {
        print(it);
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