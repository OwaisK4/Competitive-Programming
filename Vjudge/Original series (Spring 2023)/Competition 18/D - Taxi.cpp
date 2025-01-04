#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <functional>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // int array[N];
    vector<int> array(N);
    long long int cars = 0;


    for (int i=0; i<N; i++){
        cin >> array[i];
    }

    sort(array.begin(), array.end(), greater<int>());
    // vector<int>::iterator it;

    for (int i=0; i<N; i++){
        int a = array[i];
        if (a == 0)
            continue;
        else if (a < 4){
            if (a == 3){
                // it = lower_bound(array.begin() + i, array.end(), 1, greater<int>());
                auto it = lower_bound(array.rbegin(), array.rend(), 1);
                if (it != array.rend() && *it == 1){
                    cars++;
                    // array[i] = 0;
                    *it = 0;
                }
                else{
                    cars++;
                }
            }
            else if (a == 2){
                // it = lower_bound(array.begin() + i, array.end(), 2, greater<int>());
                auto it = lower_bound(array.rbegin(), array.rend(), 2);
                if (it != array.rend() && *it == 2){
                    cars++;
                    // array[i] = 0;
                    *it = 0;
                }
                else{
                    cars++;
                }
            }
            else if (a == 1){
                // it = lower_bound(array.begin() + i, array.end(), 3, greater<int>());
                auto it = lower_bound(array.rbegin(), array.rend(), 3);
                if (it != array.rend() && *it == 3){
                    cars++;
                    // array[i] = 0;
                    *it = 0;
                }
                else{
                    cars++;
                }
            }
        }
        else{
            array[i] = 0;
            cars++;
            
        }
        for (auto it : array){
            cout << it << " ";
        }
        cout << "\n";
    }    

    /*
    for (int i=0; i<N; i++){
        int a = array[i];
        if ((i+1 < N) && (a + array[i+1] <= 4)){
            int b = array[i+1];
            if ((i+2 < N) && (a + b + array[i+2] <= 4)){
                int c = array[i+2];
                if ((i+3 < N) && (a + b + c + array[i+3] <= 4)){
                    int d = array[i+3];
                    cars += 1;
                    i += 3;
                }
                else{
                    cars += 1;
                    i += 2;
                }
            }
            else{
                cars += 1;
                i += 1;
            }
        }
        else{
            cars += 1;
            i += 0;
        }
        cout << i << " ";
    }
    */

    cout << cars;

    return 0;
}