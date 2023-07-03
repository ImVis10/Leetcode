class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) { // every other person apart from the judge trusts judge, so size of the trust array should be minimum n - 1
            return -1;
        }
        
        if (trust.size() == 0 && n == 1) {
            return n;
        }
        
        map<int, int> inCount; 
        
        for (auto pair : trust) {
            inCount[pair[0]]--;
            inCount[pair[1]]++;
        }
        
        for (auto entry : inCount) {
            if (entry.second == n - 1) {
                return entry.first;
            }
        }
        return -1;
    }
};