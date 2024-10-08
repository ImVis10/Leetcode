class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int teams = skill.size() / 2;
        vector<int> freq(1001);
        int totalSkill = 0;
        for (int playerSkill : skill) {
            freq[playerSkill]++;
            totalSkill += playerSkill;
        }
        
        if (totalSkill % teams != 0) return -1;
        
        long long res = 0;
        int target = totalSkill / teams;
        
        for (int playerSkill : skill) {
            int partnerSkill = target - playerSkill;
            if (freq[partnerSkill] == 0) return -1;
            res += (long long) playerSkill * (long long) partnerSkill;
            freq[partnerSkill]--;
        }
        return res / 2;
    }
};