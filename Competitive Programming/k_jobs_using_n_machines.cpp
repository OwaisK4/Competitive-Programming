#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

bool valid(int x, int k, vector<int> array, int n){
    long long int sum = 0;
    for (int i=0; i<n; i++){
        sum += (x / array[i]);
    }
    if (sum >= k)
        return true;
    else
        return false;
}

int main(){
    int k = 8;
    int n = 3;
    vector<int> array{2, 3, 7};
    int max = *max_element(all(array));
    int limit = k * max;

    vector<long long int> times(limit);
    for (int i=0; i<limit; i++){
        times[i] = valid(i, k, array, n);
    }
    for (auto it : times){
        cout << it << " ";
    }
    cout << "\n";
    int answer = lower_bound(all(times), true) - times.begin();
    cout << answer;

    return 0;
}