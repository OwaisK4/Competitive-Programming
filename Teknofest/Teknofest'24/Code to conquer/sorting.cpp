#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    int n = nums.size();

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    sort(nums.begin(), nums.end());

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}