#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vi cost;
vi answer;
vector<bool> visited;
vector<vi> mixing;

int dfs(int source){
    if (visited[source]){
        return answer[source];
    }
    visited[source] = true;
    if (cost[source] == 0 || mixing[source].empty()){
        answer[source] = cost[source];
        return answer[source];
    }

    int total = 0;
    for (auto it : mixing[source]){
        total += dfs(it);
    }
    answer[source] = min(total, cost[source]);
    return answer[source];
}

signed main(){
    fastio;
    int t;
    int n, k;
    int m;
    cin >> t;
    while (t--){
        cin >> n >> k;
        cost.assign(n, 0);
        answer.assign(n, 0);
        visited.assign(n, false);
        for (int i=0; i<n; i++){
            cin >> cost[i];
        }
        for (int i=0; i<k; i++){
            int temp;
            cin >> temp;
            cost[temp-1] = 0;
        }
        mixing.assign(n, vector<int>());
        for (int i=0; i<n; i++){
            cin >> m;
            int temp;
            for (int j=0; j<m; j++){
                cin >> temp;
                mixing[i].push_back(temp-1);
            }
        }
        for (int i=0; i<n; i++){
            answer[i] = min(dfs(i), cost[i]);
        }

        for (int i=0; i<n; i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        answer.clear();
        visited.clear();
    }
    return 0;
}