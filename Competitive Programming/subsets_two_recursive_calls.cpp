#include <iostream>
#include <vector>
using namespace std;

void search(vector<int> subset, int k, int n) {
    if (k >= n) {
        for (int it : subset) {
            cout << it << " ";
        }
        cout << "\n";
        return;
    } else {
        subset.push_back(k);
        search(subset, k + 1, n);
        subset.pop_back();
        search(subset, k + 1, n);
    }
}

int main() {
    int N = 3;
    search(vector<int>(), 0, N);
    return 0;
}