#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int N, temp;
    cin >> N;
    stack<int> s;
    vector<int> array;
    for (int i=0; i<N; i++){
        cin >> temp;
        if (temp == 0){
            array.push_back(s.top());
            s.pop();
        }
        else{
            s.push(temp);
        }
    }
    for (auto it : array){
        cout << it << " ";
    }
    return 0;
}