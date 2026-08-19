#include <bits/stdc++.h>
using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    int start = 0, n_dup = n - 1, m_dup = m - 1;
    while (n >= 2 && m >= 2) {
        int l = (2 * n) + ((m - 2) * 2);
        int tr = r % l;
        vector<pair<int, int>> temp;
        for (int i = start, j = start; j <= m_dup; j++)
            temp.push_back({i, j});
        for (int i = start + 1, j = m_dup; i <= (n_dup - 1); i++)
            temp.push_back({i, j});
        for (int i = n_dup, j = m_dup; j >= start; j--)
            temp.push_back({i, j});
        for (int i = n_dup - 1, j = start; i >= (start + 1); i--)
            temp.push_back({i, j});
        // cout<<n<<" "<<m<<" "<<temp.size()<<" "<<l<<" "<<tr<<endl;
        // for(auto it:temp)
        // {
        //     cout<<"("<<it.first<<","<<it.second<<") ";
        // }
        // cout<<endl;
        int i, j;
        for (i = tr, j = 0; i < l; i++, j++) {
            ans[temp[j].first][temp[j].second] = matrix[temp[i].first][temp[i].second];
        }
        for (i = 0; i < tr; i++, j++) {
            ans[temp[j].first][temp[j].second] = matrix[temp[i].first][temp[i].second];
        }
        n_dup--;
        m_dup--;
        start++;
        n -= 2;
        m -= 2;
        temp.clear();
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        }
    return 0;
}