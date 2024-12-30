//
// Created by Leo Chen on 2024/12/28.
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    // [4,2,7,6,9,14,12], bricks = 5, ladders = 1
    // i = 0, diff = -2 < 0, heap = {}, bricks = 5 ladder = 1
    // i = 1, diff = 5 > 0, heap = {5}, bricks = 5 ladder = 1
    // i = 2, diff = -1 < 0, heap = {5}, bricks = 5 ladder = 1
    // i = 3, diff = 3 > 0, heap = {3, 5}, bricks = 2 ladder = 1
    // i = 4, diff = 5 > 0, heap = {3, 5, 3}, bricks = -3 ladder = 1
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                heap.push(diff);
                // if bricks is not enough, use ladder
                if (heap.size() > ladders) {
                    bricks -= heap.top();
                    heap.pop();
                }
                if (bricks < 0) {
                    return i;
                }
            }
        }
        return heights.size() - 1;
    }
};

int main() {
    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;
    Solution solution;
    int res = solution.furthestBuilding(heights, bricks, ladders);
    cout << res << endl;
    return 0;
}