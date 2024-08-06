//
// Created by Leo Chen on 2024/8/4.
//

#include <vector>
#include <stack>

using namespace std;


class CanVisitAllRooms {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        stack<int> stack;
        stack.push(0);
        while (!stack.empty()) {
            int cur = stack.top();
            stack.pop();
            for (int key: rooms[cur]) {
                if (!visited[key]) {
                    visited[key] = true;
                    stack.push(key);
                }
            }
        }
        for (bool v: visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};