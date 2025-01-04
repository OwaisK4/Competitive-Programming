#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, N;
    cin >> t;

    while (t--){
        cin >> N;
        long long int array[N];

        for (int i=0; i<N; i++){
            cin >> array[i];
        }

        long long int sum = 0;

        for (int i=0; i<N-1; i++){
            int a = array[i];
            int b = array[i+1];
            if ((0 - a - b) > (a + b)){
                array[i] = -a;
                array[i+1] = -b;
            }
        }

        for (int i=0; i<N; i++){
            // cout << array[i] << " ";
            sum += array[i];
        }
        // cout << "\n";

        cout << sum << "\n";
    }

    return 0;
}