#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    vector<int> ans;
    while (i < j)
    {
        ans.push_back(v[j]);
        ans.push_back(v[i]);
        j--;
        i++;
    }
    if (n % 2 == 1)
    {
        ans.push_back(v[i]);
    }
    int c = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
            c++;
    }
    cout << c << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
 					 			         		 		    		