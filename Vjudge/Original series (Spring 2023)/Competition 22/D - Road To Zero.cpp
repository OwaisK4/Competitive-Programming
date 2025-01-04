#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        long long int x, y, a, b;
        long long int sum = 0;
        cin >> x >> y;
        cin >> a >> b;

        if (x < 0 && y >= 0 || x >= 0 && y < 0){
            int low = min(x, y);
            int high = max(x, y);

            low = abs(low);
            sum += (low * a);

            sum += (high * a);
            cout << sum << "\n";
        }
        else{
            int low = min(x, y);
            int high = max(x, y);

            low = abs(low);
            high = abs(high);

            sum += (low * b);
            high = high - low;

            sum += (high * a);
            cout << sum << "\n";
        }
    }
    return 0;
}