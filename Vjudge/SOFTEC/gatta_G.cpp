#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long int
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<string>> hints(n, vector<string>(5));
    vector<int> array(n);
    for (int i=0; i<m; i++){
        for (int j=0; j<5; j++){
            cin >> hints[i][j];
        }
        // cin >> array[i];
    }
    int boxes = n;
    int current;
    int last = 0;
    int left = 1, right = n;
    for (int i=0; i<m; i++){
        // cout << hints[i][4] << "\n";
        // int num = array[i];
        int num = stoi(hints[i][4]);
        cout << "num = " << num << "\n";
        string direction = hints[i][2];
        if (direction == "right"){
            left = num;
            current = num + 1;
        }
        if (direction == "left"){
            right = num;
            current = num - 1;
        }
        cout << "Current = " << current << "\n";
        cout << "Last = " << last << "\n";
        if (current == last){
            cout << "-1";
            return 0;
        }
        last = num;
    }
    boxes = right - left;
    cout << boxes;
    // cout << "boxes = " << boxes << "\n";
    return 0;
}