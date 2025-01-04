#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

class functor {
public:
    int limit;
    functor(int limit) {
        this->limit = limit;
    }
    bool operator()(int value) {
        return (value * value) <= limit;
    }
};

// Returns first true value for monotonic function f. Returns high+1 if there does not exist an such that start <= x <= end and f(x) == true.
int search_first_true(int low, int high, function<bool(int)> f) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (f(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

// Returns last true value for monotonic function f. Returns low-1 if there does not exist an such that start <= x <= end and f(x) == true.
int search_last_true(int low, int high, function<bool(int)> f) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2; // Adding 1 so that mid rounds upwards i.e. ceil.
        if (f(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    functor f(81);
    int start = 1;
    int end = 15;

    int index = search_last_true(start, end, f);
    cout << index << "\n";

    index = search_first_true(start, end, f);
    cout << index << "\n";

    return 0;
}