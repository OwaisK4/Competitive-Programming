#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using pii = pair<int, int>;

signed main(){
    int n, m, temp;
    cin >> n >> m;
    queue<pii> q;
    for (int i=0; i<n; i++){
        cin >> temp;
        q.push({temp, i+1});
    }
    while (q.size() > 1){
        pii child = q.front();
        q.pop();
        child.first -= m;
        if (child.first > 0){
            q.push(child);
        }
    }
    cout << q.front().second;

    return 0;
}