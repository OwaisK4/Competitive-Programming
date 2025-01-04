#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

bool dist(int a, int b){
    int diff = abs(a - b);
    if (diff <= 1)
        return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i=0; i<m; i++){
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    int i=0, j=0;
    int count = 0;
    while (i < n && j < m){
        if (!dist(a[i], b[j])){
            if (a[i] > b[j]){
                j++;
            }
            else{
                i++;
            }
        }
        else{
            count++;
            i++;
            j++;
        }
    }
    cout << count;
    
    return 0;
}