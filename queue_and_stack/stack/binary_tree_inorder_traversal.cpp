//
// Created by Leo Chen on 2023/10/16.
//

#include <vector>
#include <set>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeInorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;

        auto curNode = root;
        while (curNode != nullptr || !s.empty()) {
            while (curNode != nullptr){
                s.push(curNode);
                curNode = curNode->left;
            }

            curNode = s.top();
            s.pop();
            result.push_back(curNode->val);
            curNode = curNode->right;
        }
        return result;
    }
};