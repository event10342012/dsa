//
// Created by Leo Chen on 2024/8/17.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        auto comp = [](int n1, int n2) { return n1 < n2; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (int s: stones) {
            heap.push(s);
        }

        while (heap.size() >= 2) {
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();
            if (x == y) {
                continue;
            } else {
                heap.push(y - x);
            }
        }

        return heap.size() == 1 ? heap.top() : 0;
    }
};


int main() {
    vector<int> nums{2, 7, 4, 1, 8, 1};

    auto *obj = new Solution();
    int res = obj->lastStoneWeight(nums);
    cout << res;
}