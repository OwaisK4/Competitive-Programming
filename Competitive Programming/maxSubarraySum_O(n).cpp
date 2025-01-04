#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

template<class Container>
void print_container(const Container& object){
	for (auto it = begin(object); it != end(object); it++){
		cout << *it << " ";
	}
	cout << "\n";
}

int maxSubarraySum(int array[], int size){
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i=0; i<size; i++){
        sum = max(array[i], sum + array[i]);
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int main(){
    const int size = 8;
    int array[size] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = maxSubarraySum(array, size);
    print_container(array);
    cout << "Max subarray sum is: " << maxSum;
    return 0;
}