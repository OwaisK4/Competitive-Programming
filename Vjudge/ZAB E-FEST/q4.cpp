#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

bool check(string a){
    string b;
    for (int i=a.size()-1; i>=0; i--){
        b.push_back(a[i]);
    }
    if (a == b){
        return true;
    }
    return false;
}

signed main(){
    //string test = "MAPTMTPATPA";
    string test = "MMMTPTTPTMTPMP";
    int N = test.size();
    int longest = 0;

    for (int i=0; i<N; i++){
        for (int j=i; j<N; j++){
            string sub = test.substr(i, j+1);
            if (check(sub)){
                //cout << "Here";
                longest = max(longest, (int) sub.size());
            }
            //cout << sub << "\n";
        }
    }
    cout << longest;
    return 0;
}
