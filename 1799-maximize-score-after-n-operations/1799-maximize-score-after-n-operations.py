class Solution:
    def maxScore(self, nums: List[int]) -> int:
        cache = collections.defaultdict(int)
        # FROM NEETCODE
        def dfs(mask, op):
            if mask in cache:
                return cache[mask]
                
            for i in range(len(nums)):
                for j in range(i + 1, len(nums)):
                    if (1 << i) & mask or (1 << j) & mask: # AND to read
                        continue;
                    newMask = mask | (1 << i) | (1 << j) # OR to write
                    score = op * math.gcd(nums[i], nums[j])
                    cache[mask] = max(cache[mask], score + dfs(newMask, op + 1))
                    
            return cache[mask]
        return dfs(0, 1)