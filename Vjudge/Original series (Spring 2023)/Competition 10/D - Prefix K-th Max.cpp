#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int P[N];
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    set<int> s;
    for (int i = 0;  i < K; i++){
        s.insert(P[i]);
    }
    
    auto it = s.begin();
    cout << *(it) << "\n";
    for (int i = K; i < N; i++){
        s.insert(P[i]);
        s.erase(s.begin());
        // auto it = next(s.begin(), s.size() - K);
        auto it = s.begin();
        cout << *(it) << "\n";
    }

    // cout << m.begin()->second;
    /*
    set<int> s;
    for (int i = 0;  i < K-1; i++){
        s.insert(P[i]);
    }
    
    for (int i = K-1; i < N; i++){
        s.insert(P[i]);
        auto it = next(s.begin(), s.size() - K);
        cout << *it << "\n";
    }
    */

    /*
    // vector<int> V(N, 0);
    // vector<int> V(K-1, 0);
    vector<int> V;

    for (int i = 0;  i < K-1; i++){
        // V.push_back(P[i]);
        // V[i] = P[i];
        vector<int>::iterator upper = upper_bound(V.begin(), V.end(), P[i]);
        V.insert(upper, P[i]);
    }
    sort(V.begin(), V.end());
    // sort(V.begin(), V.end(), greater<int>());
    
    for (int i = K-1; i < N; i++){        
        // V.push_back(P[i]);
        // V[i] = P[i];

        vector<int>::iterator upper = upper_bound(V.begin(), V.end(), P[i]);
        V.insert(upper, P[i]);
        // sort(V.begin(), V.end(), greater<int>());
        cout << V[V.size() - K] << "\n";
    }
    */
    /*
    for (int i = 0;  i < K; i++){
        V.push_back(P[i]);
    }
    sort(V.begin(), V.end(), greater<int>());
    
    for (int i = K; i < N; i++){
        cout << V[K-1] << "\n";
        V.push_back(P[i]);
        sort(V.begin(), V.end(), greater<int>());
        // vector<int>::iterator upper = lower_bound(V.begin(), V.end(), P[i]);
        // V.insert(upper, P[i]);
    }
    */
    
    // set<int> s;
    /*
    priority_queue<int> pq_outer;
    priority_queue<int, vector<int>, greater<int>> pq_inner;

    for (int i = 0; i < K; i++){
        pq_outer.push(P[i]);
        pq_inner.push(P[i]);
    }
    for (int i = K-1; i < N; i++){
        cout << pq_inner.top() << "\n";
        pq_inner.pop();
        pq_outer.push(P[i]);
        pq_inner.push(pq_outer.top());

        // while (!pq_inner.empty)
        //     pq_inner.pop();

        // pq_outer.push(P[i]);
        // for (int j = 0; j < K; i++){
        //     pq_inner.push(pq_outer);
        // }
    }
    */
    return 0;
}