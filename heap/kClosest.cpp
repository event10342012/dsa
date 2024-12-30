//
// Created by Leo Chen on 2024/12/28.
//
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        auto comp = [](vector<int> &p1, vector<int> &p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> heap(comp);
        for (auto &point: points) {
            heap.push(point);
        }

        vector<vector<int>> res{};
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};