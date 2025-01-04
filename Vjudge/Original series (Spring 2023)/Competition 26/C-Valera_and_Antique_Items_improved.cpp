#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int n, v;
    cin >> n >> v;
    map<int, int> sellers;
    // for (int i=1; i<=50; i++){
    //     sellers[i] = INT_MAX;
    // }

    int k, price;
    for (int i=0; i<n; i++){
        cin >> k;
        for (int j=0; j<k; j++){
            cin >> price;
            if (sellers.count(k) == 0){
                sellers[k] = price;
            }
            else{
                sellers[k] = min(sellers[k], price);
            }
        }
    }


    vector<int> deals;
    for (auto it : sellers){
        // cout << it.first << " " << it.second << "\n";
        if (v > it.second){
            deals.push_back(it.first);
        }
    }
    sort(all(deals));

    if (deals.size()){
        cout << deals.size() << "\n";
        for (auto it : deals){
            cout << it << " ";
        }
    }
    else{
        cout << 0;
    }

    return 0;
}