//
// Created by Leo Chen on 2023/10/8.
//

#include <vector>
#include <utility>
#include <queue>
#include <stack>


using namespace std;


class NumIslands {
public:
    int numIslands(vector<vector<char>> &grid) {
        int n_row = grid.size();
        if (n_row == 0) return 0;
        int n_col = grid[0].size();

        int num_islands{0};
        for(int r = 0; r < n_row; r++){
            for (int c = 0; c < n_col; c++){
                if(grid[r][c] == '1'){
                    stack<pair<int, int>> stack;
                    stack.push({r, c});
                    grid[r][c] = '0';
                    ++num_islands;

                    while(!stack.empty()){
                        auto rc = stack.top();
                        stack.pop();

                        int row = rc.first, col = rc.second;

                        if (row + 1 < n_row && grid[row + 1][ col] == '1'){
                            stack.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (row - 1 >= 0 && grid[row - 1][ col] == '1'){
                            stack.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (col + 1 < n_col && grid[row][ col + 1] == '1'){
                            stack.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][ col - 1] == '1'){
                            stack.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};