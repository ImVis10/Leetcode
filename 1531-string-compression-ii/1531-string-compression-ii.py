class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        cache = {}
        
        def count(idx, k, prev, prev_cnt):
            if (idx, k, prev, prev_cnt) in cache:
                return cache[(idx, k, prev, prev_cnt)]
            if k < 0:
                return 101
            if idx == len(s):
                return 0
            
            if s[idx] == prev:
                incr = 1 if prev_cnt in [1, 9, 99] else 0
                res = incr + count(idx + 1, k, s[idx], prev_cnt + 1)
            else:
                delete_char = count(idx + 1, k - 1, prev, prev_cnt)
                keep_char = 1 + count(idx + 1, k, s[idx], 1)
                res = min(delete_char, keep_char)
            cache[(idx, k, prev, prev_cnt)] = res
            return res
        return count(0, k, "", 0)
                