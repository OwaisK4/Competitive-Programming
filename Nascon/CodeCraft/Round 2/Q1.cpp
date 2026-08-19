#include <iostream>
using namespace std;

long countSubarrays(int arr[], int n, int m, int k) {
    int arrSum = 0;
    for (int i = 0; i < n; i++) {
        arrSum = arrSum + arr[i];
    }
    long countSubarrays = 0;
    if (arrSum > k) {
        int curSum = 0;
        int left = 0, right = 0;
        while (left < n) {
            while (curSum > k) {
                curSum -= arr[left];
                left++;
            }
            if (curSum + arr[right] <= k && right < n) {
                curSum += arr[right];
                countSubarrays++;
                right++;
            } else {
                left++;
                right = left;
                curSum = 0;
            }
        }
        if (m >= 2) {
            int extraCount = 0;
            if (arrSum > k) {
                int curSum = 0;
                int left = 0, right = 0;
                while (left < 2 * n) {
                    while (curSum > k) {
                        curSum -= arr[left % n];
                        left++;
                    }
                    if (curSum + arr[right % n] <= k && right < 2 * n) {
                        curSum += arr[right % n];
                        extraCount++;
                        right++;
                    } else {
                        left++;
                        right = left;
                        curSum = 0;
                    }
                }
            }
            countSubarrays = countSubarrays + (extraCount - countSubarrays) * (m - 1);
        }
    } else {
        int quotient = min(k / arrSum, m);
        int index = 0;
        int currentSum = quotient * arrSum;
        while (index < n && currentSum + arr[index] <= k && quotient < m) {
            currentSum += arr[index];
            index++;
        }
        int subarray_size = (quotient * n) + index;
        // cout << "Subarray size: " << subarray_size << endl;
        int total_size = m * n;
        int number_of_subarrays = total_size - subarray_size + 1;
        countSubarrays = (subarray_size * number_of_subarrays) + (((subarray_size) * (subarray_size - 1)) / 2);
    }
    return countSubarrays;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << countSubarrays(arr, n, m, k) << endl;
    }

    return 0;
}