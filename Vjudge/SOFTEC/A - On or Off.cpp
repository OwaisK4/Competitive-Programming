#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;

    int zero = 0, one = 0, zerozero = 0, onezero = 0, zeroone = 0;
    for (int i=0; i<n; i++){
        if (a[i] == '0'){
            zero++;
            if (b[i] == '0'){
                zerozero++;
            }
            else
                zeroone++;
        }
        else if (a[i] == '1'){
            one++;
            if (b[i] == '0'){
                onezero++;
            }
        }
    }

    int answer = zerozero * one;
    answer += (zeroone * onezero);

    cout << answer;
    return 0;
}