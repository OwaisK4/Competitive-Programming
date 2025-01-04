#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {}

signed main() {
  fastio;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}