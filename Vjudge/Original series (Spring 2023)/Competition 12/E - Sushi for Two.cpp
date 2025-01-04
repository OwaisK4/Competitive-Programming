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
    int T, N;

    cin >> N;
    int array[N];
    for (int i=0; i<N; i++){
        cin >> array[i];
    }
    int maximum = 0;
    int counter1 = 0;
    int counter2 = 0;
    int min_counter;
    int last = array[0];
    for (int i=0; i<N; i++){
        if (array[i] == last){
            if (array[i] == 1)
                counter1++;
            else
                counter2++;
            min_counter = min(counter1, counter2);
            maximum = max(min_counter * 2, maximum);
        }
        else{
            if (array[i] == 1){
                while (array[i] == 1 && i<N){
                    counter1++;
                    i++;
                }
                last = array[i];
                // if (counter1 == counter2){
                    min_counter = min(counter1, counter2);
                    maximum = max(min_counter * 2, maximum);
                    // maximum = max(counter1 * 2, maximum);
                    counter1 = 1;
                    // counter2 = 0;
                // }
            }
            else{
                while (array[i] == 2 && i<N){
                    counter2++;
                    i++;
                }
                last = array[i];
                // if (counter1 == counter2){
                    min_counter = min(counter1, counter2);
                    maximum = max(min_counter * 2, maximum);
                    // maximum = max(counter2 * 2, maximum);
                    // counter1 = 0;
                    counter2 = 1;
                // }
            }
            
        }
    }
    cout << maximum;
    
    return 0;
}