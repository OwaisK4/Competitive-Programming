#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int T[N];
    for (int i=0; i<N; i++){
        cin >> T[i];
    }
    sort(T, T + N);
    int OA = 0, OB = 0;
    for (int i=0; i<N; i+=2){
        OA += T[i];
        OB += T[i+1];
    }
    cout << min(OA, OB);
    return 0;
}