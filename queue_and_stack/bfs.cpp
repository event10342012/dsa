//
// Created by Leo Chen on 2023/8/7.
//

#include <queue>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;


class Node {
public:
    int val{0};
    vector<Node> child;

    Node() {}
};


int bfs(Node root, Node target) {
    queue<Node> q;
    set<int> visited{root.val};
    int step{0};

    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node cur = q.front();
            if (cur.val == target.val) {
                return step;
            }
            for (Node node: cur.child) {
                if (visited.count(node.val) == 0) {
                    q.push(node);
                    visited.insert(node.val);
                }
            }
            q.pop();
        }
        step++;
    }
    return -1;
}

