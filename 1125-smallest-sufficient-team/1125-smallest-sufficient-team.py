class Solution(object):
    def smallestSufficientTeam(self, req_skills, people):
        """
        :type req_skills: List[str]
        :type people: List[List[str]]
        :rtype: List[int]
        """
        # seems like a set covering problem (Grokking Algorithms book). This is an NP Complete problem.
        # So using Greedy - Approximation.
        # Pick the person that has the most required skills that have not been fulfilled yet. It's OK if the person                  covers the skills that have been covered already.
        # Repeat the above until all the required skills are fulfilled.
        # TLE with Greedy approach, so got the solution from DISCUSS section
        num_skills = len(req_skills)
        skill_to_index_map = {skill : index for index, skill in enumerate(req_skills)}
        print(skill_to_index_map)
        dp = {0: []}
        for i, person in enumerate(people):
            person_skill = 0
            for skill_required in person:
                if skill_required in skill_to_index_map:
                    person_skill |= 1 << skill_to_index_map[skill_required]
            for skill_set, need in dp.items():
                with_person = skill_set | person_skill
                if with_person == skill_set: continue
                if with_person not in dp or len(dp[with_person]) > len(need) + 1:
                    dp[with_person] = need + [i]
        return dp[(1 << num_skills) - 1]
        
        