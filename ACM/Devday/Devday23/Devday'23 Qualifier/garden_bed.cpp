#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int temp;
    int N, K;
    cin >> N  >> K;
    set<int> s;
    s.insert(0);
    s.insert(N);
    for (int i=0; i<K; i++){
        cin >> temp;
        s.insert(temp);
        int gap, max_gap = 0;
        for (auto it = s.begin(); it != s.end(); it++){
            if (next(it) == s.end())
                continue;
            int l = *it;
            int u = *next(it);
            gap = u - l;
            cout << gap << " ";
            max_gap = max(max_gap, gap);
        }
        cout << "\n";
    }
    return 0;
}