#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, a, b;
    map<int, int> n1, n2;
    cin >> N;

    for (int i = 0; i < N; i+=2){
        cin >> a >> b;
        n1[a]++;
        n2[b]++;
    }

    // for (auto it : n2){
    //     cout << it.first << " " << it.second << "\n";
    // }

    vector<pair<int, int>> v1, v2;

    for (auto it : n1){
        v1.push_back({it.second, it.first});
    }
    for (auto it : n2){
        v2.push_back({it.second, it.first});
    }

    sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    sort(v2.begin(), v2.end(), greater<pair<int, int>>());

    if (v1[0].second != v2[0].second){
        cout << N - v1[0].first - v2[0].first;
    }
    else{
        cout << min((N - v1[0].first - v2[1].first), (N - v1[1].first - v2[0].first));
    }

    return 0;
}