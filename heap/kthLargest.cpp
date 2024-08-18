//
// Created by Leo Chen on 2024/8/17.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class KthLargest {
private:
    int k{0};
    priority_queue<int, vector<int>, greater<>> heap;
public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int i: nums) {
            add(i);
        }
    }

    int add(int val) {
        if (heap.size() < k || val > heap.top()) {
            heap.push(val);
            if (heap.size() > k){
                heap.pop();
            }
        }
        return heap.top();
    }
};

int main() {
    vector<int> nums{4, 5, 8, 2};
    auto *obj = new KthLargest(3, nums);
    int param_1 = obj->add(3);
    param_1 = obj->add(5);
    param_1 = obj->add(10);
    param_1 = obj->add(9);
    param_1 = obj->add(4);
    delete obj;
}