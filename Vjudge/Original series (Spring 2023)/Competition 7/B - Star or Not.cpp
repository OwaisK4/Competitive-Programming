#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool flag = false;
    int N, a, b;
    cin >> N;
    vector<vector<int>> graph(N + 1);
    for (int i=0; i<N-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // for (int i=0; i<N-1; i++){
    //     // if (i == N){
    //         // break;
    //     // }
    //     // if (graph[i].size() == N - 1)
    //     //     cout << "Yes";
    //     cout << graph[i].size() << "\n";
    // }
    for (auto it : graph){
        // cout << it.size() << " ";
        if (it.size() == N - 1){
            cout << "Yes";
            flag = true;
        }
    }
    if (!flag)
        cout << "No";
    graph.clear();
    return 0;
}