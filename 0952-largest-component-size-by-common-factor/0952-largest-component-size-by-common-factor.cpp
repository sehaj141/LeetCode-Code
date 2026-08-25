#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

class UnionFind {
public:
    std::vector<int> parent;
    
    UnionFind(int n) : parent(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
};

class Solution {
public:
    int largestComponentSize(std::vector<int>& nums) {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        UnionFind uf(maxVal + 1);
        
        // Union each number with its prime factors
        for (int num : nums) {
            for (int factor = 2; factor * factor <= num; ++factor) {
                if (num % factor == 0) {
                    uf.unite(num, factor);
                    uf.unite(num, num / factor);
                }
            }
        }
        
        // Count the component sizes among the elements of nums
        std::unordered_map<int, int> count;
        int maxComponent = 0;
        
        for (int num : nums) {
            int root = uf.find(num);
            maxComponent = std::max(maxComponent, ++count[root]);
        }
        
        return maxComponent;
    }
};