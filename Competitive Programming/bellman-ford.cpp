#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();

void push_back(vector<tuple<int, int, int>>& edges, int a, int b, int w){
    edges.push_back({a, b, w});
}

int main(){
    vector<tuple<int, int, int>> edges;
    push_back(edges, 1, 2, 3);
    push_back(edges, 1, 3, 5);
    push_back(edges, 2, 3, 2);
    push_back(edges, 2, 4, 1);
    push_back(edges, 3, 4, -7);

    int N = 4;
    int distance[N + 1] = {INF / 2};

    distance[0] = 0;
    for (int i = 1; i < N; i++){
        for (auto e : edges){
            int a, b, w;
            tie(a, b, w) = e;
            distance[b] = min(distance[b], distance[a] + w);
        }
    }
    for (int i = 0; i <= N; i++){
        cout << distance[i] << " ";
    }
    cout << "\n";
    // cout << distance[0];
    return 0;
}