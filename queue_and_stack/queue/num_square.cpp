//
// Created by Leo Chen on 2023/9/23.
//

#include <vector>
#include <iostream>
#include <set>


using namespace std;

class NumSquares {
private:
    set<int> square_nums;

public:
    int numSquares(int n) {
        for (int i = 1; i * i <= n; ++i) {
            square_nums.insert(i * i);
        }

        int count = 1;
        for (; count <= n; ++count) {
            if (is_divided_by(n, count)) {
                return count;
            }
        }
        return count;
    }

    bool is_divided_by(int n, int count) {
        if (count == 1) {
            return square_nums.find(n) != square_nums.end();
        }

        for (int square : square_nums) {
            if (is_divided_by(n - square, count - 1)) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    NumSquares sol = *new NumSquares();

    int res = sol.numSquares(1);
    cout << res;
}