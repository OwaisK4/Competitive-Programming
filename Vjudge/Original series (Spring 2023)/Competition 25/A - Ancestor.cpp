#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> P(N+1);

    for (int i=2; i<=N; i++){
        cin >> P[i];
    }

    int i = N;
    int count = 0;
    while (i != 1){
        i = P[i];
        count++;
    }
    cout << count;
    
    return 0;
}