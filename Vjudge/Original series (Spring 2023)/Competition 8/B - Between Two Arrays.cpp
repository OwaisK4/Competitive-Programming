#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    // int A[N], B[N];
    vector<int> A(N), B(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
    }
    
    int count = 0;
    int minA = *min_element(A.begin(), A.end());
    int maxA = *max_element(A.begin(), A.end());

    int minB = *min_element(B.begin(), B.end());
    int maxB = *max_element(B.begin(), B.end());

    for (int i=minA; i<=maxB; i++){
        for (int j=minA; j<=maxB; j++){
            if (i > j)
                continue;
            // cout << i << " " << j << "\n";
            // count = (count + 1) % 998244353;
            count++;
        }
    }
    // cout << pow(2, count);

    return 0;
}