class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int firstInstanceAt = findFirstInstance(nums, target);
        
        // if the element at firstInstanceAt + nums.size() / 2 is still target, then it is a majority element. No need to check for the rest
        return (firstInstanceAt + n / 2 < n) && (nums[firstInstanceAt + n / 2] == target);
    }

private:
    int findFirstInstance(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int firstInstanceAt = 0;        
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
        return firstInstanceAt;
    }
    
    int findLastInstance(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int lastInstanceAt = -1;        
        // find the next index of last instance 
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                lastInstanceAt = mid;
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            }
        }
        return lastInstanceAt;
    }
    
};