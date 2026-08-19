#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    fastio;
    int n, k;
    cin >> n >> k;

    vector<int> passwords;
    for (int i=0; i<n; i++){
        string temp;
        cin >> temp;
        passwords.push_back(temp.size());
    }
    string real;
    cin >> real;
    int real_size = real.size();

    sort(all(passwords));
    int counter = 0;
    int i;
    int time = 0;

    // print(passwords);
    for (i=0; i<n; i++){
        if (passwords[i] == real_size){
            i++;
            time++;
            counter++;
            break;
        }
        if (k == counter || k == 1){
            time += 5;
            time++;
            counter = 0;
            counter++;
        }
        else{
            time++;
            counter++;
        }
    }
    if (k < counter){
        time += 5;
        counter = 0;
    }
    cout << time << " ";

    for (; i<n; i++){
        if (passwords[i] > real_size){
            // time++;
            break;
        }
        if (k == counter || k == 1){
            time += 5;
            time++;
            counter = 0;
            counter++;
        }
        else{
            time++;
            counter++;
        }
    }
    cout << time;

    return 0;
}