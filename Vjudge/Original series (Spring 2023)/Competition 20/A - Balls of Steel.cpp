#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;
using pii = pair<int, int>;

int distance(pii coord1, pii coord2){
    int answer = abs(coord1.first - coord2.first) + abs(coord1.second - coord2.second);
    return answer;
}

int main(){
    int t, n, k;
    cin >> t;

    while (t--){
        cin >> n >> k;
        vector<pair<int, int>> balls(n);
        for (int i=0; i<n; i++){
            cin >> balls[i].first >> balls[i].second;
        }
        bool flag;
        for (int i=0; i<n; i++){
            flag = true;
            for (int j=0; j<n; j++){
                if (j == i)
                    continue;
                if (distance(balls[i], balls[j]) > k){
                    flag = false;
                }
            }
            if (flag){
                cout << 1 << "\n";
                break;
            }
        }
        if (!flag){
            cout << -1 << "\n";
        }
    }
    return 0;
}