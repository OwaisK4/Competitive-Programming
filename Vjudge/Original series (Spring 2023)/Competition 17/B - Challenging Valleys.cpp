#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        int N;
        cin >> N;
        vector<int> array(N);
        
        for (int i=0; i<N; i++){
            cin >> array[i];
        }
        
        if (N == 0 || N == 1){
            cout << "YES\n";
            continue;
        }

        int counter = 0;
        for (int i=0; i<N-1; i++){
            if (counter == 0){
                if (array[i+1] > array[i])
                    counter++;
            }
            if (counter == 1){
                if (array[i+1] < array[i])
                    counter++;
            }
        }
        // cout << "Counter = " << counter << " ";
        if (counter < 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}