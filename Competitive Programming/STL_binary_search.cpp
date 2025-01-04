#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define nl cout << "\n"
using namespace std;

int main()
{
    int n = 100;
    vector<int> array(n);
    int i = 0;
    for (auto &it : array) {
        it = i++;
    }
    // for (auto it : array){
    //     cout << it << " ";
    // }
    // auto a = equal_range(all(array), 50);
    // cout << *(a.first) << " " << *(a.second);
    vector<bool> vec(10, false);
    fill(vec.begin() + 5, vec.end(), true);
    for (auto it : vec){
        cout << it << " ";
    } nl;
    auto x = lower_bound(all(vec), true);
    cout << (x - vec.begin());
    // auto x = equal_range(all(vec), true);
    // cout << (x.first - vec.begin());
    return 0;
}