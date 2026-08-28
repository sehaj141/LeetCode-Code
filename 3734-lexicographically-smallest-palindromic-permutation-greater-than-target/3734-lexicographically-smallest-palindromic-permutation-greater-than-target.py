from collections import Counter

class Solution(object):
    def lexPalindromicPermutation(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: str
        """
        n = len(s)
        counts = Counter(s)
        
        # Step 1: Check palindrome validity
        odd_chars = [char for char, cnt in counts.items() if cnt % 2 != 0]
        if len(odd_chars) > 1:
            return ""
        
        mid_char = odd_chars[0] if odd_chars else ""
        
        # Step 2: Build frequency counts for the first half
        half_counts = {char: cnt // 2 for char, cnt in counts.items()}
        half_len = n // 2
        
        # Utility to generate the smallest palindrome given fixed prefix of first half
        def build_smallest_palindrome(prefix_list, remaining_counts):
            first_half = list(prefix_list)
            for char in sorted(remaining_counts.keys()):
                first_half.extend([char] * remaining_counts[char])
            
            first_half_str = "".join(first_half)
            second_half_str = first_half_str[::-1]
            return first_half_str + mid_char + second_half_str

        # Step 3: Try to match target prefix of length `i` (from half_len down to 0)
        for i in range(half_len, -1, -1):
            prefix = target[:i]
            
            # Check if target[:i] is a valid prefix using our available half_counts
            prefix_counts = Counter(prefix)
            if any(prefix_counts[char] > half_counts.get(char, 0) for char in prefix_counts):
                continue
            
            # Calculate remaining available characters for the half
            rem_counts = {char: half_counts[char] - prefix_counts.get(char, 0) for char in half_counts}
            
            # Case A: Full match on the first half (i == half_len)
            if i == half_len:
                candidate = prefix + mid_char + prefix[::-1]
                if candidate > target:
                    return candidate
                continue
            
            # Case B: Match first `i` characters, pick a larger character at index `i`
            needed_char = target[i]
            sorted_chars = sorted(rem_counts.keys())
            
            for next_char in sorted_chars:
                if next_char > needed_char and rem_counts[next_char] > 0:
                    # Place next_char at index i
                    temp_prefix = list(prefix) + [next_char]
                    temp_rem = dict(rem_counts)
                    temp_rem[next_char] -= 1
                    
                    candidate = build_smallest_palindrome(temp_prefix, temp_rem)
                    if candidate > target:
                        return candidate
                        
        return ""