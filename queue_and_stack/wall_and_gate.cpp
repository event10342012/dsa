//
// Created by Leo Chen on 2023/8/8.
//

#include <climits>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    const static int empty = INT_MAX;
    const static int gate = 0;

public:
    void wallsAndGates(vector<vector<int> > &rooms) {
        const static vector<vector<int>> directions = {
                vector<int>({1, 0}),
                vector<int>({-1, 0}),
                vector<int>({0, 1}),
                vector<int>({0, -1})
        };

        unsigned long m = rooms.size();
        if (m == 0) return;
        unsigned long n = rooms[0].size();
        queue<vector<int>> q;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (rooms[row][col] == gate) {
                    q.push(vector<int>({row, col}));
                }
            }
        }

        while (!q.empty()) {
            vector<int> point = q.front();
            q.pop();

            int row = point[0];
            int col = point[1];

            for (vector<int> direction: directions) {
                int r = row + direction[0];
                int c = col + direction[1];

                if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != empty) {
                    continue;
                }
                rooms[r][c] = rooms[row][col] + 1;
                q.push(vector<int>({r, c}));
            }
        }
    }
};