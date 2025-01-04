#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <random>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

template <typename T>
void debug(T *array, int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

bool valid(int x, int k, int *array, int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += x / array[i];
    }
    if (sum >= k)
        return true;
    else
        return false;
}

int binary_search(int* array, int n, int upper_bound, int k){
    int x = -1;
    for (int b = upper_bound/2; b >= 1; b /= 2){
        while (!valid(x + b, k, array, n))
            x += b;
    }
    return x + 1;
}

int main(){
    int k = 8;
    int n = 3;
    int *array = new int[n]{2, 3, 7};
    int max = *max_element(array, array + n);
    int upper_bound = k * max;
    int answer = binary_search(array, n, upper_bound, k);
    cout << answer;

    return 0;
}