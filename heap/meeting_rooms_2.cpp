#include <map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        // 1. sort start time
        sort(intervals.begin(), intervals.end());

        // 2. create a min heap to track the end time
        priority_queue<int, vector<int>, std::greater<>> heap;
        heap.push(0);

        int res = 1;
        // 3. iterate through the intervals
        for (auto interval: intervals) {
            if (interval[0] >= heap.top()) {
                heap.pop();
            } else {
                res++;
            }
            heap.push(interval[1]);
        }

        return res;
    }
};


int main() {
    vector<vector<int>>
    interval{{0, 30}, {5, 10}, {15, 20}};
    auto *obj = new Solution{};
    cout << obj->minMeetingRooms(interval);
    delete obj;
    }
