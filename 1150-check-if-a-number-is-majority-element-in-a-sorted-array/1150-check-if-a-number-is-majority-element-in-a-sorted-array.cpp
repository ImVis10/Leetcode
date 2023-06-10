class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int firstInstanceAt = 0;
        int cnt = 0;
        
        // find the index of first instance 
        while (low <= high) {
            int mid = (low + high) / 2;
            if ((mid == 0 || nums[mid - 1] < target) && nums[mid] == target) {
                firstInstanceAt = mid;
                break;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        for (int i = firstInstanceAt; i < nums.size(); i++) {
            if (nums[i] != target) {
                break;
            }
            cnt++;
        }
        
        return cnt > nums.size() / 2;
    }
    
};