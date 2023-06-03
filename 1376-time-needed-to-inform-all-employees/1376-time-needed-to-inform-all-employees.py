class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = collections.defaultdict(list) # manager -> list of employees
        for i in range(n):
            adj[manager[i]].append(i)
        
        q = deque([(headID, 0)])
        
        res = 0
        
        while q:
            empId, time = q.popleft()
            res = max(res, time)
            for employee in adj[empId]:
                q.append([employee, time + informTime[empId]])
        return res