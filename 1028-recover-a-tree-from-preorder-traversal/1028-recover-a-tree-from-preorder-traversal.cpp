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
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> st;
        int i = 0, n = traversal.size();

        while (i < n) {
            // Step 1: Count dashes to determine the depth of the current node
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Step 2: Read the node's numerical value
            int val = 0;
            while (i < n && traversal[i] >= '0' && traversal[i] <= '9') {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            // Step 3: Pop until the stack size equals the node's depth
            while (st.size() > depth) {
                st.pop_back();
            }

            // Step 4: Attach the node to its parent
            if (!st.empty()) {
                if (!st.back()->left) {
                    st.back()->left = node;
                } else {
                    st.back()->right = node;
                }
            }

            // Step 5: Push current node to maintain the active path
            st.push_back(node);
        }

        // The bottom of the stack is always the root
        return st.front();
    }
};