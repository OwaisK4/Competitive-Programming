#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    long long int n;
    cin >> n;

    vector<long long int> start, end;
    for (int i=0; i<n; i++){
        long long int a, b;
        cin >> a >> b;
        start.push_back(a);
        end.push_back(b);
    }
    sort(all(start));
    sort(all(end));

    // for (int i=0; i<n; i++){
    //     cout << start[i] << " ";
    // }

    long long int i=0, j=0;
    long long int count = 0, max_count = 0;
    while (i < n && j < n){
        if (start[i] < end[j]){
            count++;
            i++;
            max_count = max(max_count, count);
        }
        else if (start[i] > end[j]){
            count--;
            j++;
        }
    }
    cout << max_count;

    return 0;
}