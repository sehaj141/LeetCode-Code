class Solution(object):
    def countLatticePoints(self, circles):
        """
        :type circles: List[List[int]]
        :rtype: int
        """
        # Step 1: Find the global bounding box for all circles
        min_x = min(x - r for x, y, r in circles)
        max_x = max(x + r for x, y, r in circles)
        min_y = min(y - r for x, y, r in circles)
        max_y = max(y + r for x, y, r in circles)
        
        count = 0
        
        # Step 2: Iterate over every lattice point in the bounding box
        for x in range(min_x, max_x + 1):
            for y in range(min_y, max_y + 1):
                # Step 3: Check if (x, y) lies inside at least one circle
                for cx, cy, r in circles:
                    if (x - cx) ** 2 + (y - cy) ** 2 <= r ** 2:
                        count += 1
                        break  # Count once per point and move to next (x, y)
                        
        return count