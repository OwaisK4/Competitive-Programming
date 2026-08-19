#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

vector<vector<int>> t;
vector<int> points;
vector<int> penalty;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int tests;
    cin >> tests;
    while(tests--){
        int n, m, h;
        cin >> n >> m >> h;
        t.assign(n, vector<int>(m));
        points.assign(n, 0);
        penalty.assign(n, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> t[i][j];
            }
            sort(all(t[i]));
            int k=0;
            int time = 0;
            while (k < m && (time + t[i][k]) <= h){
                points[i]++;
                time += (t[i][k]);
                penalty[i] += time;
                k++;
            }
        }
        int rank = 1;
        int rudolf_points = points[0];
        int rudolf_penalty = penalty[0];
        for (int i=1; i<n; i++){
            if (rudolf_points < points[i]){
                rank++;
            }
            else if (rudolf_points == points[i]){
                if (rudolf_penalty > penalty[i]){
                    rank++;
                }
            }
        }
        cout << rank << "\n";
    }
    return 0;
}