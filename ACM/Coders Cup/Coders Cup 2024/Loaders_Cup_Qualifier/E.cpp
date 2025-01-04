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

string s;
int n;
vector<vector<int>> dp;

int f(int l, int r) {
  if (l >= r) {
    return 0;
  }
  if (dp[l][r] != -1) {
    return dp[l][r];
  }

  int answer = INT_MAX;
  if (s[l] == s[r]) {
    answer = min(answer, f(l + 1, r - 1));
  } else {
    answer = min(answer, f(l + 1, r) + 1);
    answer = min(answer, f(l, r - 1) + 1);
    // answer = min(answer, f(l + 1, r - 1) + 2);
  }
  return dp[l][r] = answer;
}

void solve() {
  cin >> s;
  n = s.size();
  dp.assign(n + 1, vector<int>(n + 1, -1));
  int answer = f(0, n - 1);
  cout << answer;
}

signed main() {
  fastio;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": ";
    solve();
    cout << endl;
  }

  return 0;
}