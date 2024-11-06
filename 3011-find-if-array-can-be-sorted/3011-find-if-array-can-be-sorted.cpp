class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int minOfGrp = nums[0], maxOfGrp = nums[0];
        int setbitCnt = countSetBits(nums[0]), maxOfPrevGrp = INT_MIN;;
        for (int i = 1; i < n; i++) {
            if (countSetBits(nums[i]) == setbitCnt) {
                minOfGrp = min(minOfGrp, nums[i]);
                maxOfGrp = max(maxOfGrp, nums[i]);
            } else if (minOfGrp < maxOfPrevGrp) {
                return false;
            } else {
                maxOfPrevGrp = maxOfGrp;
                minOfGrp = nums[i];
                maxOfGrp = nums[i];
                setbitCnt = countSetBits(nums[i]);
            }
        }
        return !(minOfGrp < maxOfPrevGrp);
    }
private:
    int countSetBits(int num) {
        int cnt = 0;
        while (num) {
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
    
    bool haveSameNumberOfSetBits(int a, int b) {
        return countSetBits(a) == countSetBits(b);
    }
};