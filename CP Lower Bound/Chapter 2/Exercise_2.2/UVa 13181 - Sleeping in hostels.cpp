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
    string s;
    while (cin >> s){
        int answer = 0;
        // if (count(all(s), 'X') == 1){
        int leftpos = s.find('X');
        int start = leftpos - 0 - 1;
        int rightpos = s.rfind('X');
        int end = s.size() - rightpos - 2;
        answer = max(start, end);
    // 
        start = 0, end = 0;
        while ((end = s.find('X', start)) != s.npos){
            int dist = end - start;
            if (dist % 2 == 0){
                dist--;
            }
            dist = dist / 2;
            answer = max(answer, dist);
            start = end + 1;
        // }
        }
        cout << answer << "\n";
    }
}