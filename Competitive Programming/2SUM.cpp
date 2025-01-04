#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

vector<pair<int, int>> K_SUM(vector<int> c, int k){
    int i = 0;
    int j = c.size() - 1;
    vector<pair<int, int>> result;
    while (i <= j){
        if (c[i] + c[j] == k){
            result.push_back({c[i], c[j]});
            i++;
            j--;
        }
        else if (c[i] + c[j] < k){
            i++;
        }
        else{
            j--;
        }
    }
    return result;
}

int main(){
    srand(time(0));
    vector<int> a(10);
    transform(all(a), a.begin(), [](auto _){static int x=0; return x++;});

    // default_random_engine rng((random_device())());
    // shuffle(all(a), rng);
    // sort(all(a));
    
    for (auto &it : a){
        cout << it << " ";
    }
    cout << "\n";

    int k = 10;
    auto result = K_SUM(a, k);
    for (auto it : result){
        cout << it.first << ", " << it.second << "\n";
    }
}