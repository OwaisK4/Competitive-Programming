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

int binary_search(int* array, int size, int key){
    int k = 0;
    for (int b = size/2; b >= 1; b /= 2){
        while (k+b < size && array[k+b] <= key){
            k += b;
        }
    }
    if (array[k] == key)
        return k;
    else
        return -1;
}

int main(){
    srand(time(0));
    const int size = 10;
    int *array = new int[size];
    transform(array, array + size, array, [](int){ static int i=0; return i++; });

    // auto rng = default_random_engine{};
    // shuffle(array, array + size, rng);
 
    debug(array, size);
    int found = binary_search(array, size, 5);
    cout << found;

    return 0;
}