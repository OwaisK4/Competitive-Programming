#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
const int k = 5;

template <typename T>
void debug(T *array, int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

bool possible(int x, int k, int weights[]){
    if (k == 0){
        if (x == 0)
            return true;
        else
            return false;
    }
    else{
        return (possible(x-weights[k-1], k-1, weights) || possible(x, k-1, weights));
    }
}

int main(){
    // Recursive solution
    const int size = 4;
    int weights[size] = {1, 3, 3, 5};
    int x = 10;
    bool answer = possible(x, size, weights);
    cout << answer;

    // DP Iterative solution
    int dp;
    return 0;
}