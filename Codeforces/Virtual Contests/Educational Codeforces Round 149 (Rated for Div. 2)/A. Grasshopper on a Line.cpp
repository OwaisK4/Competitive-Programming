#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;
using pii = pair<int, int>;

signed main(){
    int t;
    cin >> t;

    while (t--){
        int x, k;
        cin >> x >> k;

        if (x < k || (x % k)){
            cout << 1 << "\n";
            cout << x << "\n";
            continue;
        }

        vector<int> answer;
        int jump = x;
        while (jump % k == 0){
            jump--;
        }
        answer.push_back(jump);
        int current = jump;
        int z = x;

        while (current < x){
            while (((x - jump) % k) == 0){
                jump--;
            }
            current += (x - jump);
            answer.push_back(x - jump);
            // z = current;
        }
        cout << answer.size() << "\n";
        for (auto it : answer){
            cout << it << " ";
        }
        cout << "\n";

    }
    return 0;
}