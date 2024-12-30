//
// Created by Leo Chen on 2024/12/28.
//

#include <queue>
#include <vector>

using namespace std;


class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int stick: sticks) {
            heap.push(stick);
        }

        int cost = 0;
        while(heap.size() > 1){
            // let me do it myself
            int stick1 = heap.top();
            heap.pop();
            int stick2 = heap.top();
            heap.pop();
            int new_stick = stick1 + stick2;
            cost += new_stick;
            heap.push(new_stick);
        }
        return cost;
    }
};