#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN

using namespace std;

signed main(){
    int t, n, k;
    string s;
    char special;

    cin >> t;
    while (t--){
        cin >> n >> s;
        cin >> k;
        unordered_map<char, int> c;
        for (int i=0; i<k; i++){
            cin >> special;
            c[special]++;
        }

        // priority_queue<int> dist;
        int dist = 0;

        int last=0, current=0;
        for (current = 0; current < n; current++){
            if (c.count(s[current]) != 0){
                // dist.push(current - last);
                dist = max(dist, current - last);
                last = current;
            }
        }
        // if (!dist.empty()){
        //     cout << dist.top() << "\n";
        // }
        // else{
        //     cout << 0 << "\n";
        // }
        cout << dist << "\n";
    }
}