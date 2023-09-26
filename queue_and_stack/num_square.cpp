//
// Created by Leo Chen on 2023/9/23.
//

#include <vector>
#include <iostream>


using namespace std;

class NumSquares {
private:
    vector<int> squares;
public:
    int numSquares(int n) {
        for (int i = 1; (i ^ 2) < n; i++) {
            squares.push_back(i ^ 2);
        }
        return minNumSquares(n);
    }

    int minNumSquares(int n) {
        for (int k: squares) {
            if (k == n) {
                return 1;
            }
        }
        int minNum = INT32_MAX;

        for (int k: squares) {
            if (k == n) {
                return 1;
            }

            if (k < n) {
                break;
            }

            int newNum = minNumSquares(n - k) + 1;
            minNum = min(minNum, newNum);
        }
        return minNum;
    }
};


int main() {
    NumSquares sol = *new NumSquares();

    int res = sol.numSquares(12);
    cout << res;
}