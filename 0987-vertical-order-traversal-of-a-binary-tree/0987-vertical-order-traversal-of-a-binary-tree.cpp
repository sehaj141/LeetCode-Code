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
#include <vector>
#include <map>
#include <set>
#include <queue>

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        // map<col, map<row, multiset<val>>>
        std::map<int, std::map<int, std::multiset<int>>> nodes;
        
        // Queue holds pairs of {TreeNode*, {row, col}}
        std::queue<std::pair<TreeNode*, std::pair<int, int>>> q;
        if (root) {
            q.push({root, {0, 0}});
        }
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            TreeNode* curr = front.first;
            int row = front.second.first;
            int col = front.second.second;
            
            nodes[col][row].insert(curr->val);
            
            if (curr->left) {
                q.push({curr->left, {row + 1, col - 1}});
            }
            if (curr->right) {
                q.push({curr->right, {row + 1, col + 1}});
            }
        }
        
        std::vector<std::vector<int>> result;
        for (auto& [col, rowMap] : nodes) {
            std::vector<int> colGroup;
            for (auto& [row, multiSet] : rowMap) {
                colGroup.insert(colGroup.end(), multiSet.begin(), multiSet.end());
            }
            result.push_back(colGroup);
        }
        
        return result;
    }
};