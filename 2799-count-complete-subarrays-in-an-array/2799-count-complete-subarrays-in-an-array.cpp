class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
//         set<int> set(nums.begin(), nums.end());
//         int distinct = set.size(), res = 0;
        
//         set.clear();
        
//         int start = 0, end = 0;
//         while (end < nums.size()) {
//             if (set.count(nums[end]) == 0) {
//                 set.insert(nums[end]);
//                 distinct -= 1;
//             }
//             if (end < nums.size() && distinct == 0) {
//                 res++;
//                 if (end == nums.size() - 1) {
//                     start++;
//                     end = start;
//                     distinct = set.size();
//                     set.clear();
//                     continue;
//                 }
//             }
//             end++;
//         }
//         return res;
        
        // My solution iterates through the array multiple times and travels through the same parts again and again, (albeit reducing the distance travelled in each iteration) but it is not exactly linear time. So looked up the approach by lee215
        
        int distinct = unordered_set(nums.begin(), nums.end()).size();
        
        int res = 0, n = nums.size();
        
        unordered_map<int, int> freq;
        
        for (int start = 0, end = 0; end < n; end++) {
            if (freq[nums[end]]++ == 0) { // if the current element was not in the subarray, decrement distinct
                distinct -= 1;
            }
            
            while (distinct == 0) { // we've found a subarray which is complete
                if (--freq[nums[start]] == 0) { // if the number is not in the subarray anymore, increment distinct
                    distinct += 1;
                }
                start++; // move the start to right, until the subarray is not complete anymore
            }
            
            res += start; // subarrays ending at 'end' and starting at or before 'start' are complete
        }
        return res;
    }
};