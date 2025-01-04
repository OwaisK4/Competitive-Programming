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
    int P[N], Q[N];

    for (int i=0; i<N; i++){
        cin >> P[i];
    }
    for (int i=0; i<N; i++){
        Q[P[i] - 1] = i + 1;
    }
    for (int i=0; i<N; i++){
        cout << Q[i] << " ";
    }
    return 0;
}