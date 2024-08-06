//
// Created by Leo Chen on 2024/8/4.
//

#include <vector>
#include <queue>


using namespace std;

class Matrix {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>> matrix(m, vector<int>(n, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<vector<int>> queue;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = mat[row][col];
                if (mat[row][col] == 0) {
                    queue.push({row, col, 0});
                    seen[row][col] = true;
                }
            }
        }

        while (!queue.empty()) {
            vector<int> cur = queue.front();
            queue.pop();
            int row = cur[0], col = cur[1], step = cur[2];

            for (auto direction: directions) {
                int next_row = row + direction[0], next_col = col + direction[1];
                if (valid(next_row, next_col) && !seen[next_row][next_col]) {
                    seen[next_row][next_col] = true;
                    queue.push({next_row, next_col, step + 1});
                    matrix[next_row][next_col] = step + 1;
                }
            }
        }
        return matrix;
    }


    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};