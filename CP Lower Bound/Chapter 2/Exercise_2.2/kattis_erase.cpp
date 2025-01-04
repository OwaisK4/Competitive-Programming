#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto& it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    int N;
    cin >> N;

    string a, b;
    cin >> a >> b;

    if (N % 2 == 0){
        if (a == b){
            cout << "Deletion succeeded";
        }
        else{
            cout << "Deletion failed";
        }
    }
    else{
        for (int i=0; i<a.size(); i++){
            if (a[i] == '0')
                a[i] = '1';
            else
                a[i] = '0';
        }
        if (a == b){
            cout << "Deletion succeeded";
        }
        else{
            cout << "Deletion failed";
        }
    }

    
    return 0;
}