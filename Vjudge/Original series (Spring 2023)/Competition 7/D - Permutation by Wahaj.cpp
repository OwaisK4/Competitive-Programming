#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // vectors have size (n + 1) because input ranges from 1 to n (inclusive)
    vector<vector<int>> graph(n + 1); // adjacency list for graph
    vector<int> indegree(n + 1);      // counts the number of edges going into a vertex
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        // a imposes a constraint on b, so the edge goes from a to b
        graph[a].push_back(b);
        // increase the number of edges going into b
        ++indegree[b];
    }
    // priority queue provides access to smallest element first
    // is is used here because we need to build the lexicographically smallest sequence
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        // if any element has indegree equal to 0, it is not effected by any constraints
        // therefore, it is available for placement in the result
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    // this vector will contain the actual answer sequence
    vector<int> result;
    // we loop while there are elements left in the priority queue
    while (!pq.empty()) {
        // get the smallest element available for placement
        int cur = pq.top();
        // remove the element from the priority queue
        pq.pop();
        // add it to the result
        result.push_back(cur);
        // loop over all elements that were constrained by the current one
        for (int i = 0; i < graph[cur].size(); ++i) {
            int neighbour = graph[cur][i];
            // remove the edge from current element to its neighobur
            --indegree[neighbour];
            // if the neighbour now has indegree equal to 0, it is not effected by any constraints
            // therefore, it is available for placement in the result
            if (indegree[neighbour] == 0) {
                pq.push(neighbour);
            }
        }
    }
    // if all n elements were placed in the result, we have a solution
    if (result.size() == n) {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ' ';
        }
    } else {
        // otherwise, a solution is not possible
        cout << -1;
    }
}

/*
    a priority queue declared normally like this:
        priority_queue<int> pq;
    accesses the maximum element first

    to build a priority queue that accesses smaller elements first:
        priority_queue<int, vector<int>, greater<int>> pq;
 */
