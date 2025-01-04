#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int n, m;
    long long int k;
    cin >> n >> m >> k;

    vector<long long int> applicants(n), apartments(m);
    for (int i=0; i<n; i++){
        cin >> applicants[i];
    }
    for (int i=0; i<m; i++){
        cin >> apartments[i];
    }
    sort(all(applicants));
    sort(all(apartments));

    int count = 0;
    for (long long int i=0, j=0; i<n && j<m; ){
        if ((applicants[i] + k) < apartments[j]){
            i++;
        }
        else if ((applicants[i] - k) > apartments[j]){
            j++;
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