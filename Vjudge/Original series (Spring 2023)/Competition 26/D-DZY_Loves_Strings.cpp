#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    string s;
    int k;
    vector<int> w(26);
    int max_value = INT_MIN;

    cin >> s >> k;
    for (int i=0; i<26; i++){
        cin >> w[i];
        max_value = max(max_value, w[i]);
    }

    int sum = 0;
    int i;
    for (i=0; i<s.size(); i++){
        int alpha = s[i] - 97;
        sum += ((i+1) * w[alpha]);
    }
    for (int j=0; j<k; j++){
        sum += ((i+1) * max_value);
        i++;
    }
    cout << sum;

    return 0;
}