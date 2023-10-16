//
// Created by Leo Chen on 2023/10/12.
//


#include <vector>
#include <stack>

using namespace std;

class TargetSum {
private:
    int count{0};
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        calculate(nums, 0, 0, target);
        return count;
    }

    void calculate(vector<int> &nums, int i, int sum, int target) {
        if (i == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            calculate(nums, i + 1, sum + nums[i], target);
            calculate(nums, i + 1, sum - nums[i], target);
        }
    }
};