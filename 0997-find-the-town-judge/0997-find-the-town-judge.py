class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        # Every person in the village trusts the judge, so there needs to be atleast n - 1 sub lists in the trust list
        if len(trust) < n - 1:
            return -1
        
        count = [0] * (n + 1) # start index is 1 so going till n + 1
        
        for truster, trustee in trust:
            count[truster] -= 1
            count[trustee] += 1
            
        for i, cnt in enumerate(count[1:], 1):
            if cnt == n - 1: # judge is the only person whose is trusted by all except him/herself i.e. whose count is equal to n - 1
                return i
        
        return -1
            
        