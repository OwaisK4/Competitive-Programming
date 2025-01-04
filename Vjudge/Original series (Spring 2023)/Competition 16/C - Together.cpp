#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <climits>
#define rep(i,a,n) for (int i=a; i<n; i++)
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a(100002);
    int N, X;
    cin >> N;

    rep(i, 0, N){
        cin >> X;
        if (X != 0)
            a[X-1]++;
        a[X]++;
        a[X+1]++;
    }

    int maximum = *max_element(all(a));

    cout << maximum;

    return 0;
}