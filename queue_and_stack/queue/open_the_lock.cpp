//
// Created by Leo Chen on 2023/8/22.
//

#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class OpenTheLock {
public:
    int openLock(vector<string> &deadends, string target) {
        if (target == "0000") return 0;
        queue<int> queue;
        queue.push(0);
        bool seen[10000]{false};

        for (auto &d: deadends)
            seen[stoi(d)] = true;

        int targ = stoi(target);

        if (seen[0]) return -1;

        for (int turns = 1; queue.size(); turns++) {
            int qlen = queue.size();
            for (int i = 0; i < qlen; i++) {
                int curr = queue.front();
                queue.pop();
                for (int j = 1; j < 10000; j *= 10) {
                    int mask = curr % (j * 10) / j, masked = curr - (mask * j);
                    for (int k = 1; k < 10; k += 8) {
                        int next = masked + (mask + k) % 10 * j;
                        if (seen[next]) continue;
                        if (next == targ) return turns;
                        seen[next] = true;
                        queue.push(next);
                    }
                }
            }
        }
        return -1;
    }
};


int main() {
    OpenTheLock sol = *new OpenTheLock();
    vector<string> d1{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    vector<string> d2{"0201", "0101", "0102", "1212", "2002"};
    int res1 = sol.openLock(d1, "8888");
    int res2 = sol.openLock(d2, "0202");

    cout << res1 << ' ' << res2;
}