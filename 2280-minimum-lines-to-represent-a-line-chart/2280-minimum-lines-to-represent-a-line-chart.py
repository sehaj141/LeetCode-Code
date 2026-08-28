class Solution(object):
    def minimumLines(self, stockPrices):
        """
        :type stockPrices: List[List[int]]
        :rtype: int
        """
        n = len(stockPrices)
        if n <= 1:
            return 0
        
        # Step 1: Sort prices by day
        stockPrices.sort(key=lambda x: x[0])
        
        # We need at least 1 line for 2 or more points
        lines = 1
        
        # Step 2: Traverse from the 3rd point onward and check for slope changes
        for i in range(2, n):
            x1, y1 = stockPrices[i - 2]
            x2, y2 = stockPrices[i - 1]
            x3, y3 = stockPrices[i]
            
            # Cross-multiplication to compare slopes:
            # (y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2)
            dx1, dy1 = x2 - x1, y2 - y1
            dx2, dy2 = x3 - x2, y3 - y2
            
            if dy1 * dx2 != dy2 * dx1:
                lines += 1
                
        return lines