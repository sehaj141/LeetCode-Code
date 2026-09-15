/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>

using namespace std;

class Solution {
private:
    int dfs(TreeNode* node, int currentMin, int currentMax) {
        if (!node) {
            // Reached past a leaf; difference for this path is max - min
            return currentMax - currentMin;
        }

        // Update the running min and max along the current path
        currentMin = min(currentMin, node->val);
        currentMax = max(currentMax, node->val);

        // Recurse on left and right subtrees and take the maximum result
        int leftDiff = dfs(node->left, currentMin, currentMax);
        int rightDiff = dfs(node->right, currentMin, currentMax);

        return max(leftDiff, rightDiff);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val, root->val);
    }
};