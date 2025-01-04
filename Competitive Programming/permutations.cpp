#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void permute(string &source, int left, int right, vector<string> &permutations) {
    if (left == right) {
        permutations.push_back(source);
    } else {
        for (int i = left; i <= right; i++) {

            swap<char>(source[left], source[i]);
            permute(source, left + 1, right, permutations);
            swap<char>(source[left], source[i]); // Backtracking condition
        }
    }
}

int main() {
    fstream file("output.txt", ios::out);
    string source = "ABCDE";
    // string source = "ABCDEFGHIJ";
    size_t size = source.size();
    vector<string> permutations;
    permute(source, 0, size - 1, permutations);
    for (auto &it : permutations) {
        // cout << it << "\n";
        file << it << "\n";
    }
    return 0;
}