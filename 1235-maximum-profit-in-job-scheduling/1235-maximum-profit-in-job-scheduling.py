class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # FROM NEETCODE
        intervals = sorted(zip(startTime, endTime, profit))
        cache = {}
        def dfs(i):
            if i == len(intervals):
                return 0
            if i in cache:
                return cache[i]
            # don't include
            res = dfs(i + 1)
            # include
            # j = i + 1
            # while j < len(intervals):
            #     curr_end = intervals[i][1]
            #     next_start = intervals[j][0]
            #     if curr_end <= next_start: # here we are searching for the first start time that is greater than the curr end time, we can employ binary search instead of sequential iteration
            #         break
            #     j += 1
            
            # BINARY SEARCH TO FIND THE FIRST START TIME THAT IS GREATER THAN CURRENT END TIME
            curr_end = intervals[i][1]
            j = bisect.bisect(intervals, (curr_end, -1, -1))
            res = max(res, intervals[i][2] + dfs(j)) # curr interval profit + next jobs's supposed profit
            cache[i] = res
            return res
        
        return dfs(0)