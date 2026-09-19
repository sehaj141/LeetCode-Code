#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point (closestX, closestY) on the rectangle to the circle center
        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Check if the squared distance is within the squared radius
        return dx * dx + dy * dy <= radius * radius;
    }
};