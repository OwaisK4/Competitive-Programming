#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// findCommon(list1, list2) -> the number common elements between the two lists
// assume that there are no duplicate elements in list1 and list2
// say a == b if fabs(a - b) < EPS

// template<typename T, typename C = equal_to<T>>
// int findCommon(vector<T> const& a, vector<T> const& b, C const& cmp = C()) {
//     unordered_set<T, hash<T>, C> set_a(a.begin(), a.end(), cmp);
//     auto commonCount = 0;
//     for (auto elem : b) {
//         commonCount += set_a.count(elem);
//     }
//     return commonCount;
// }

// a, b, c, we consider them as common only if a==b, b==c and a==c
// a=[0, 0.011] b=[0.005] c=[0.0012]
// a[0], b[0]
template <typename T, typename C = equal_to<T>>
int findCommon(vector<vector<T>> lists, C const &cmp = C()) {
    if (lists.empty()) {
        return 0;
    }
    sort(lists.front().begin(), lists.front().end());
    auto result = lists.front();
    for (auto i = 1UL; i < lists.size(); ++i) {
        sort(lists[i].begin(), lists[i].end());
        vector<T> currentResult;
        set_intersection(result.begin(), result.end(), lists[i].begin(), lists[i].end(), back_inserter(currentResult), cmp);
        result = currentResult;
    }
    return result.size();
}

template <typename C>
int findCommon(vector<vector<float>> lists, C const &cmp) {
    if (lists.empty()) {
        return 0;
    }
    sort(lists.front().begin(), lists.front().end());
    auto result = lists.front();
    unordered_map<float, vector<float>, hash<float>, C>
        mp(cmp);
    for (auto elem : result) {
        mp[result].push_back(result);
    }
    for (auto i = 1UL; i < lists.size(); ++i) {
        auto right = lists[i];
        sort(right.begin(), right.end());

        vector<float> currentResult;
        auto j = 0, k = 0;
        while (j < result.size() && k < right.size()) {
            if (cmp(result[j], right[k])) {
                auto ok = true;
                for (auto old : mp[result[j]]) {
                    ok = ok && cmp(old, right[k]);
                }
                if (ok) {
                    currentResult.push_back(result[j]);
                    mp[result[j]].push_back(right[k]);
                }
            } else if (result[j] < right[k]) {
                ++j;
            } else {
                ++k;
            }
        }
        result = currentResult;
    }
    return result.size();
}

int main() {
    float EPS = 0.01f;
    auto float_cmp = [EPS](float x, float y) {
        return fabs(x - y) < EPS;
    };
    vector<float> a = {1.0, 4.0, 3.0};
    vector<float> b = {3.0, 2.0, 1.0};
    vector<float> c = {4.0, 2.0, 1.0};
    cout << findCommon(vector<vector<float>>{a, b, c}, float_cmp) << '\n';
    return 0;
}
