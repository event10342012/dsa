//
// Created by Leo Chen on 2023/10/7.
//

#include <vector>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

class DailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < temperatures.size(); i++){
            while (!stack.empty() && stack.top().first < temperatures[i]){
                result[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({temperatures[i], i});
        }
        return result;
    }
};


int main() {
    vector<int> x = {73, 74, 75, 71, 69, 72, 76, 73};
    DailyTemperatures *sol = new DailyTemperatures();
    for (int i: sol->dailyTemperatures(x)) {
        cout << i << ' ';
    }
}