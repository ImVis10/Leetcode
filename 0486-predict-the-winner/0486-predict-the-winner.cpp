class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int totalScore = accumulate(nums.begin(), nums.end(), 0);
        int scoreP1 = getP1Score(nums, 0, nums.size() - 1);
        int scoreP2 = totalScore - scoreP1;
        return scoreP1 >= scoreP2;
    }
private:
    int getP1Score(vector<int>& nums, int leftEnd, int rightEnd) { 
        if (leftEnd > rightEnd) return 0;
        
        if (leftEnd == rightEnd) return nums[leftEnd];
        
        int scoreP1 = max(nums[leftEnd] + min(getP1Score(nums, leftEnd + 2, rightEnd), getP1Score(nums, leftEnd + 1, rightEnd - 1)),
                         nums[rightEnd] + min(getP1Score(nums, leftEnd, rightEnd - 2), getP1Score(nums, leftEnd + 1, rightEnd - 1)));
        return scoreP1;
    }
};