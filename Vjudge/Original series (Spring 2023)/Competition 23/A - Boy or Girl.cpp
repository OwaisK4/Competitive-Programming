#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <climits>
using namespace std;

int main(){
    //freopen("input", "r", stdin);
    map<char, int> mp;
    string s;
    cin >> s;
    for (auto it : s){
        mp[it]++;
    }
    if (mp.size() % 2 == 0){
        cout << "CHAT WITH HER!";
    }
    else{
        cout << "IGNORE HIM!";
    }
    return 0;
}
