#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
using namespace std;

int main(){
    vector<string> s;
    string temp;
    while (cin >> temp){
        s.push_back(temp);
    }
    for (auto it : s){
        cout << it << " ";
    }
}