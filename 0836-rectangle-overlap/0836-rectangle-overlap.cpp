#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        // Overlap condition:
        // 1. Overlap along the x-axis: rec1[0] < rec2[2] && rec1[2] > rec2[0]
        // 2. Overlap along the y-axis: rec1[1] < rec2[3] && rec1[3] > rec2[1]
        
        return (rec1[0] < rec2[2] && rec1[2] > rec2[0]) &&
               (rec1[1] < rec2[3] && rec1[3] > rec2[1]);
    }
};