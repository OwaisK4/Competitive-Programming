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

int solve(int x, vector<int> coins){      // Returns the number of ways to produce sum x, using k coins.
    if (x == 0)
        return 1;
    else if (x < 0)
        return 0;
    int sum = 0;
    for (auto c : coins){
        sum += solve(x - c, coins);
    }
    return sum;
}

int main(){
    // Recursive solution
    vector<int> coins = {1, 3, 4};
    int x = 5;
    int answer = solve(x, coins);
    cout << answer << "\n";

    //Iterative Dynamic Programming Solution
    const int N = 100000;
    const int INF = numeric_limits<int>::max() - 1;
    int count[N];
    
    count[0] = 1;
    for (int i = 1; i <= N; i++){
        for (auto c : coins){
            if (i - c >= 0){
                count[i] += count[i - c];
            }
        }
    }
    cout << count[30];

    return 0;
}