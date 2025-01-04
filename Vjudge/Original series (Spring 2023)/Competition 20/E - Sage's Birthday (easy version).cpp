#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(all(v));
    int count = 0;

    for (int i=0; i<n-1; i+=2){
        swap<int>(v[i], v[i+1]);
    }

    for (int i=1; i<n-1; i++){
        if (v[i-1] > v[i] && v[i] < v[i+1])
            count++;
    }

    cout << count << "\n";
    for (auto& it : v){
        cout << it << " ";
    }

    return 0;
}