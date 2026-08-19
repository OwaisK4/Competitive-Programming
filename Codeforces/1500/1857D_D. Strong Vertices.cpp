#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

signed main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 0), b(n, 0), ans(n, 0), shahid;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = a[i] - b[i];
            // cout << "ans[i] = " << ans[i] << "\n";
        }
        int maxi = *max_element(ans.begin(), ans.end());
        for (int i = 0; i < n; i++){
            if (ans[i] == maxi)
                shahid.push_back(i+1);
        }
        cout << shahid.size() << endl;
        for (int i = 0; i < shahid.size(); i++)
        {
            cout << shahid[i] << " ";
        }
        cout << endl;
    }
    return 0;
}