class Node {
public:
    int left, right;           // Range boundaries [left, right]
    int leftMax, rightMax, max; // leftMax: max repeating from left boundary
                                // rightMax: max repeating from right boundary  
                                // max: max repeating in this range

    Node(int l, int r)
        : left(l)
        , right(r)
        , leftMax(1)
        , rightMax(1)
        , max(1) {}
};

class SegmentTree {
private:
    string str;                 // The string we're tracking
    vector<Node*> tree;         // Segment tree nodes

    // Build the segment tree recursively
    void build(int nodeIdx, int left, int right) {
        tree[nodeIdx] = new Node(left, right);
      
        // Leaf node - single character
        if (left == right) {
            return;
        }
      
        // Build left and right subtrees
        int mid = (left + right) >> 1;
        build(nodeIdx << 1, left, mid);
        build(nodeIdx << 1 | 1, mid + 1, right);
      
        // Update current node based on children
        pushUp(nodeIdx);
    }

    // Update parent node based on its children
    void pushUp(int nodeIdx) {
        Node* root = tree[nodeIdx];
        Node* leftChild = tree[nodeIdx << 1];
        Node* rightChild = tree[nodeIdx << 1 | 1];
      
        // Take the maximum from both children
        root->max = max(leftChild->max, rightChild->max);
      
        // Initialize left and right max from children
        root->leftMax = leftChild->leftMax;
        root->rightMax = rightChild->rightMax;
      
        // Calculate range sizes
        int leftRangeSize = leftChild->right - leftChild->left + 1;
        int rightRangeSize = rightChild->right - rightChild->left + 1;
      
        // Check if we can merge at the boundary
        if (str[leftChild->right - 1] == str[rightChild->left - 1]) {
            // If left child is fully repeating, extend into right child
            if (leftChild->leftMax == leftRangeSize) {
                root->leftMax += rightChild->leftMax;
            }
          
            // If right child is fully repeating, extend into left child
            if (rightChild->rightMax == rightRangeSize) {
                root->rightMax += leftChild->rightMax;
            }
          
            // Update max considering the merge at boundary
            root->max = max(root->max, leftChild->rightMax + rightChild->leftMax);
        }
    }

public:
    // Constructor - build segment tree from string
    SegmentTree(const string& s)
        : str(s) {
        int n = s.size();
        tree.resize(n * 4);     // Allocate space for segment tree
        build(1, 1, n);         // Build tree with 1-indexed positions
    }

    // Modify character at position x to value v
    void modify(int nodeIdx, int position, char value) {
        // Found the leaf node to update
        if (tree[nodeIdx]->left == position && tree[nodeIdx]->right == position) {
            str[position - 1] = value;  // Update string (convert to 0-indexed)
            return;
        }
      
        // Recursively find the correct leaf
        int mid = (tree[nodeIdx]->left + tree[nodeIdx]->right) >> 1;
        if (position <= mid) {
            modify(nodeIdx << 1, position, value);
        } else {
            modify(nodeIdx << 1 | 1, position, value);
        }
      
        // Update current node after modification
        pushUp(nodeIdx);
    }

    // Query the maximum repeating substring length in range [left, right]
    int query(int nodeIdx, int left, int right) {
        // Current node is completely within query range
        if (tree[nodeIdx]->left >= left && tree[nodeIdx]->right <= right) {
            return tree[nodeIdx]->max;
        }
      
        int mid = (tree[nodeIdx]->left + tree[nodeIdx]->right) >> 1;
        int result = 0;
      
        // Query left child only
        if (right <= mid) {
            result = query(nodeIdx << 1, left, right);
        } 
        // Query right child only
        else if (left > mid) {
            result = max(result, query(nodeIdx << 1 | 1, left, right));
        }
      
        return result;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        // Initialize segment tree with the string
        SegmentTree segTree(s);
      
        int numQueries = queryIndices.size();
        vector<int> result(numQueries);
        int stringLength = s.size();
      
        // Process each query
        for (int i = 0; i < numQueries; ++i) {
            int position = queryIndices[i] + 1;  // Convert to 1-indexed
            char newChar = queryCharacters[i];
          
            // Update the character at position
            segTree.modify(1, position, newChar);
          
            // Query the entire string for longest repeating substring
            result[i] = segTree.query(1, 1, stringLength);
        }
      
        return result;
    }
};
