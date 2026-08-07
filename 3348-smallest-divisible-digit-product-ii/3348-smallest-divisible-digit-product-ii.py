class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        prime_factors = {2: 0, 3: 0, 5: 0, 7: 0}
        temp_t = t
        for p in [2, 3, 5, 7]:
            while temp_t % p == 0:
                prime_factors[p] += 1
                temp_t //= p
        
        if temp_t > 1:
            return "-1"

        def get_digit_factors(d: int):
            counts = {2: 0, 3: 0, 5: 0, 7: 0}
            if d in (2, 4, 8):
                counts[2] = 1 if d == 2 else (2 if d == 4 else 3)
            elif d in (3, 9):
                counts[3] = 1 if d == 3 else 2
            elif d == 5:
                counts[5] = 1
            elif d == 6:
                counts[2] = 1
                counts[3] = 1
            elif d == 7:
                counts[7] = 1
            return counts

        def min_digits_needed(factors: dict) -> list[int]:
            """Returns the lexicographically smallest sorted list of digits 
            with minimum length that satisfies the factor requirements."""
            f2, f3 = max(0, factors[2]), max(0, factors[3])
            f5, f7 = max(0, factors[5]), max(0, factors[7])
            
            best_digits = None
            
            # Try all valid count of 6s (from 0 up to min(f2, f3))
            for cnt6 in range(min(f2, f3) + 1):
                rem2 = f2 - cnt6
                rem3 = f3 - cnt6
                
                cnt8, rem2 = divmod(rem2, 3)
                cnt4, rem2 = divmod(rem2, 2)
                cnt2 = rem2
                
                cnt9, rem3 = divmod(rem3, 2)
                cnt3 = rem3
                
                curr = ([2] * cnt2 + [3] * cnt3 + [4] * cnt4 + [5] * f5 + 
                        [6] * cnt6 + [7] * f7 + [8] * cnt8 + [9] * cnt9)
                curr.sort()
                
                if best_digits is None:
                    best_digits = curr
                elif len(curr) < len(best_digits):
                    best_digits = curr
                elif len(curr) == len(best_digits) and curr < best_digits:
                    best_digits = curr
                    
            return best_digits

        n = len(num)
        prefix_factors = [{2: 0, 3: 0, 5: 0, 7: 0} for _ in range(n + 1)]
        first_zero = n
        
        for i, ch in enumerate(num):
            d = int(ch)
            if d == 0:
                first_zero = i
                break
            df = get_digit_factors(d)
            for p in [2, 3, 5, 7]:
                prefix_factors[i + 1][p] = prefix_factors[i][p] + df[p]
        
        # 1. Check if num itself works
        if first_zero == n:
            if all(prefix_factors[n][p] >= prime_factors[p] for p in [2, 3, 5, 7]):
                return num

        # 2. Try prefix matching up to index i, incrementing digit at i
        for i in range(n - 1, -1, -1):
            if i > first_zero:
                continue
            
            curr_d = int(num[i])
            for next_d in range(curr_d + 1, 10):
                needed = {}
                next_df = get_digit_factors(next_d)
                for p in [2, 3, 5, 7]:
                    needed[p] = prime_factors[p] - prefix_factors[i][p] - next_df[p]
                
                suffix_digits = min_digits_needed(needed)
                avail_space = n - 1 - i
                
                if len(suffix_digits) <= avail_space:
                    ones = [1] * (avail_space - len(suffix_digits))
                    res_suffix = "".join(map(str, ones + suffix_digits))
                    return num[:i] + str(next_d) + res_suffix

        # 3. Expand total length
        suffix_digits = min_digits_needed(prime_factors)
        target_len = max(n + 1, len(suffix_digits))
        ones = [1] * (target_len - len(suffix_digits))
        return "".join(map(str, ones + suffix_digits))