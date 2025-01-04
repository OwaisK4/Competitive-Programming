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

void solve() {
  int fact = 1;
  vector<int> factorials;
  for (int i = 1; i <= 21; i++) {
    // cout << fact << endl;
    factorials.push_back(fact);
    fact *= i;
  }
  int N;
  cin >> N;
  int index = lower_bound(all(factorials), N) - factorials.begin();
  vector<int> answer;
  for (; index >= 0; index--) {
    if (N - factorials[index] >= 0) {
      N -= factorials[index];
      answer.push_back(index);
    }
    if (N == 0) {
      break;
    }
  }
  if (N > 0) {
    cout << "impossible";
  } else {
    reverse(all(answer));
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << "!";
      if (i < answer.size() - 1) {
        cout << "+";
      }
    }
  }
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