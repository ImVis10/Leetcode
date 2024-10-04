class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // two sum logic
        int n = skill.size();
        int teams = n / 2, totalSkill = 0;
        vector<int> freq(1001);
        for (int playerSkill : skill) {
            freq[playerSkill]++;
            totalSkill += playerSkill;
        }
        
        if (totalSkill % teams != 0) return -1;
        
        int target = totalSkill / teams;
        long long res = 0;
        for (int playerSkill : skill) {
            int partnerSkill = target - playerSkill;
            if (freq[partnerSkill] == 0) return -1;
            res += (long long) playerSkill * (long long) partnerSkill;
            freq[partnerSkill]--;
        }
        return res / 2;
    }
};