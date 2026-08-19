#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;


int f(int h){
    if (h == 1){
        return 2;
    }
    else{
        int answer = f(h-1) + h*f(1) + h - 1;
        return answer;
    }
}

signed main(){
    fastio;
    int t;
    cin >> t;
    vector<int> array(t), diff(t-1);
    for (int i=0; i<t; i++){
        array[i] = f(i+1);
    }
    for (int i=1; i<t; i++){
        diff[i-1] = array[i] - array[i-1];
    }
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";

    for (auto it : diff){
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}