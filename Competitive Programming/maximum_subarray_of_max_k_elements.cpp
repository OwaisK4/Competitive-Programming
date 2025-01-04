#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

int max_subarray_sum(vector<int> vec, int k){
    int sum = 0;
    int best = numeric_limits<int>::min();
    deque<int> array;

    for (int i=0; i<vec.size(); i++){
        if (array.size() >= k){
            if (array.front() < 0){
                sum -= array.front();
                array.pop_front();
                i--;
            }
            else{
                sum -= array.front();
                array.pop_front();
                sum += vec[i];
                array.push_back(vec[i]);
            }
        }

        else{
            if (sum + vec[i] > sum){
                sum = sum + vec[i];
                array.push_back(vec[i]);
            }
            else{
                sum = vec[i];
                array.clear();
                array.push_back(vec[i]);
            }
        }

        best = max(best, sum);
    }

    return best;
}

signed main(){
    srand(time(0));
    vector<int> a(10);
    transform(all(a), a.begin(), [](auto _){return (rand() % 20) - 10;});

    for (auto &it : a){
        cout << it << " ";
    }
    cout << "\n";

    int k = 4;
    int answer = max_subarray_sum(a, k);
    cout << "Maximum Subarray Sum = " << answer << "\n";

    return 0;
}