#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
#define int long long int
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<string>> hints(m, vector<string>(5));
    for (int i=0; i<m; i++){
        for (int j=0; j<5; j++){
            cin >> hints[i][j];
        }
    }
    int left = 1, right = n;
    int leftmost = left;
    int rightmost = right;
    for (int i=0; i<m; i++){
        int num = stoi(hints[i][4]);
        string direction = hints[i][2];
        if (direction == "right"){
            left = num + 1;
            leftmost = max(leftmost, left);
        }
        if (direction == "left"){
            right = num - 1;
            rightmost = min(rightmost, right);
        }
        if (right < left){
            cout << "-1";
            return 0;
        }
        if (left < 1 || right > n){
            cout << "-1";
            return 0;
        }
    }
    // int boxes = right - left + 1;
    int boxes = rightmost - leftmost + 1;
    cout << boxes;
    return 0;
}