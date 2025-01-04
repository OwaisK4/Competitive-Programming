#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    int X[N];
    for (int i=0; i<N; i++){
        cin >> X[i];
    }

    long long int sum = 0, minSum = INT_MAX;
    for (int P = (*min_element(X, X+N)); P <= (*max_element(X, X+N)); P++){
        sum = 0;
        for (int j=0; j<N; j++){
            sum += pow(X[j] - P, 2);
        }
        minSum = min(sum, minSum);
    }
    cout << minSum;
}