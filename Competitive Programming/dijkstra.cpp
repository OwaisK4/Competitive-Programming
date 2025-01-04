#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <climits>
using namespace std;

void push_back(vector<pair<int, int>> adj[], int a, int b, int w){
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}

int main(){
    int N;
    vector<pair<int, int>> adj[N+1];
    int distance[N+1] = {INT_MAX};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    return 0;
}