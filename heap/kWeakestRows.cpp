//
// Created by Leo Chen on 2024/8/18.
//

#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        map<int, int> map;
        for (int i = 0; i < mat.size(); i++) {
            int num_of_soldiers = 0;
            for (int j: mat[i]) {
                num_of_soldiers += j;
            }
            map[i] = num_of_soldiers;
        }

        auto comp = [&map](int r1, int r2) {
            if (map[r1] == map[r2]) {
                return r1 > r2;
            }
            return map[r1] > map[r2];
        };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (int i = 0; i < map.size(); i++) {
            heap.push(i);
        }

        vector<int> res{};
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};