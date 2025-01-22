/// Source : https://leetcode.com/problems/convert-bst-to-greater-tree/
/// Author : liuyubobobo
/// Time   : 2021-02-09
/// Updated: 2021-08-09

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {

        dfs(root, 0);
        return root;
    }

private:
    int dfs(TreeNode* node, int t){

        if(!node) return 0;

        int rsum = dfs(node->right, t);
        int lsum = dfs(node->left, node->val + rsum + t);
        int ret = lsum + rsum + node->val;
        node->val += rsum + t;
        return ret;
    }
};


int main() {

    return 0;
}
