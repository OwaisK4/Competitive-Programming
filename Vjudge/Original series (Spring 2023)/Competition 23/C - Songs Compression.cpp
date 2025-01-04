#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main()
{
    long long int n, m, a, b;
    long long int sum_A = 0, sum_B = 0;
    cin >> n >> m;
    vector<long long int> diff(n);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        diff[i] = a - b;
        sum_A += a;
        sum_B += b;
    }

    if (sum_B > m) {
        cout << "-1";
    }
    else if (sum_A <= m) {
        cout << 0;
    }
    else {
        sort(all(diff), greater<long long int>());
        long long int count = 0;

        for (int i = 0; i < n; i++) {
            if (sum_A <= m) {
                break;
            }
            sum_A -= diff[i];
            count++;
        }
        cout << count;
    }
    return 0;
}