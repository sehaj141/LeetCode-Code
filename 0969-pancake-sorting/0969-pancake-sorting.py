class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        res = []
        n = len(arr)
        
        for curr_val in range(n, 1, -1):
            # Find current position of curr_val
            idx = arr.index(curr_val)
            
            # If it's already in the correct position, no flips needed
            if idx == curr_val - 1:
                continue
                
            # Step 1: Flip curr_val to the front (index 0) if it isn't there
            if idx != 0:
                res.append(idx + 1)
                arr[:idx + 1] = reversed(arr[:idx + 1])
                
            # Step 2: Flip curr_val to its target sorted position (index curr_val - 1)
            res.append(curr_val)
            arr[:curr_val] = reversed(arr[:curr_val])
            
        return res