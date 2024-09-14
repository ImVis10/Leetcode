class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), cnt = 1, res = 1;
        int largest = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] == largest) {
                if (i == 0) continue;
                if (nums[i] == nums[i - 1]) {
                    cnt += 1;
                }
            } else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        cout << largest << endl;
        return max(res, cnt);
    }
};