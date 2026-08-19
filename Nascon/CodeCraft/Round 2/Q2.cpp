#include <iostream>
using namespace std;

int minPartitions(const string &n) {
    int size = n.length();
    int partitions = 0;
    for (int i = 0; i < size; i++) {
        int bit = n[i] - '0';
        if (bit > partitions) {
            partitions = bit;
        }
    }
    return partitions;
}

int main() {
    string n;
    cin >> n;
    int answer = minPartitions(n);
    cout << answer << endl;

    return 0;
}