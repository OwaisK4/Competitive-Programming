#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int n, v;
    cin >> n >> v;
    vii sellers;
    int k;
    for (int i=0; i<n; i++){
        cin >> k;
        vector<int> prices(k);
        for (int j=0; j<k; j++){
            cin >> prices[j];
        }
        int min_price = *min_element(all(prices));
        // sellers[i] = {min_price, k};
        sellers.push_back({min_price, k});
    }

    vector<int> deals;
    for (int i=0; i<n; i++){
        // cout << sellers[i].first << " " << sellers[i].second << "\n";
        if (v > sellers[i].first){
            deals.push_back(sellers[i].second);
        }
    }
    sort(all(deals));

    cout << deals.size() << "\n";
    if (deals.size() > 0){
        for (auto it : deals){
            cout << it << " ";
        }
    }

    return 0;
}