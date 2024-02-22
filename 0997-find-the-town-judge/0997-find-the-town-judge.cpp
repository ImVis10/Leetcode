class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int normalPeople = trust.size();
        if (normalPeople < n - 1 or normalPeople == n) return -1;
        if (normalPeople == 0 and n == 1) return 1;
        unordered_map<int, int> numTrust;
        for (auto& persons : trust) {
            numTrust[persons[0]]--;
            numTrust[persons[1]]++;
        }
        for (auto &[k, v] : numTrust) {
            if (v == n - 1) return k;
        }
        return -1;
    }
};