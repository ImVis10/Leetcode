class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if len(jobDifficulty) < d:
            return -1
        cache = {}
        def recurse(idx, d, curr_max):
            if idx == len(jobDifficulty):
                return 0 if d == 0 else float("inf")
            if d == 0:
                return float("inf")
            if (idx, d, curr_max) in cache:
                return cache[(idx, d, curr_max)]
            curr_max = max(curr_max, jobDifficulty[idx])
            continue_day = recurse(idx + 1, d, curr_max)
            end_day = curr_max + recurse(idx + 1, d - 1, -1)
            res = min(continue_day, end_day)
            cache[(idx, d, curr_max)] = res
            return res
        return recurse(0, d, -1)