#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

template <typename T>
void debug(T *array, int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

const int N = 1000000;
const int INF = numeric_limits<int>::max() - 1;
bool ready[N] = {};
int first[N] = {};
int value[N] = {INF};

int main(){
    vector<int> coins = {1, 3, 4};
    int n = 10;
    value[0] = 0;
    for (int x=1; x<=n; x++){
        value[x] = INF;
        for (auto c : coins){
            if (x-c >= 0 && value[x-c] + 1 < value[x]){
                value[x] = value[x-c] + 1;
                first[x] = c;
            }
            // if (x-c >= 0){
            //     value[x] = min(value[x], value[x-c] + 1);
            //     first[x] = c;
            // }
        }

    }
    for (int i=0; i<=n; i++){
        cout << value[i] << "\n";
    }

    while (n > 0){
        cout << first[n] << " ";
        n -= first[n];
    }
    return 0;
}