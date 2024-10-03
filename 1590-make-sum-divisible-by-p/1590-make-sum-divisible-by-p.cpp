class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // DISCUSS SECTION SOLUTION
        /**
        1. Calculate the rem = sum(nums) % p, which means we need to remove a subarray which has sum % p == rem to make the rest sum divisible by p.
        2. It also requires that the removed subarray should be the shortest subarray.
        3. Then the question becomes: Find the shortest array with sum(subarray) % p == rem.
        4. Since we need the shortest length, last[remainder] = idx records the last index that (A[0] + A[1] + ... + A[i]) % p == remainder.
        5. Everytime, we find a possible sum, we need get the right-most index to make sure that the subarray removed is the shortest.
        6. If there is no element what we want, then i - (-N) > N. Since we cannot remove the whole array, therefore, return res when res < N.**/
        int n = nums.size();
        // int sum = accumulate(nums.begin(), nums.end(), 0); // can't use this as it might overflow
        int target = 0;
        for (int num : nums) {
            target = (target + num) % p;
        }
        // int target = sum % p;
        int currSum = 0, res = n;
        
        if (target == 0) return 0;
        
        unordered_map<int, int> mp = {{0, -1}}; // records the last idx of remainder i.e. remainder -> last idx it is seen at
        
        for (int i = 0; i < n; i++) {
            currSum = (currSum + nums[i]) % p;
            mp[currSum] = i;
            int prefix = (currSum - target + p) % p; // the prefix that we want to remove so that the sum(current subarray) % p == target
            // 'prefix' represents the remainder of a previous prefix sum that you want to find in the map (mp). If such a remainder exists in mp, the subarray from that previous index to the current index i is a candidate for removal, and you can update the result (res) accordingly.
            if (mp.find(prefix) != mp.end()) {
                res = min(res, i - mp[prefix]);
            }
        }
        return res < n ? res : -1;
        
    }
};