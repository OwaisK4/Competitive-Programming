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

    int A[3];
    cin >> A[0] >> A[1] >> A[2];

    do {
        if ((A[2] - A[1]) == (A[1] - A[0])){
            cout << "Yes";
            return 0;
        }
    } while (next_permutation(A, A+3));
    cout << "No";
    return 0;
}