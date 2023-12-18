class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        
        int largest = INT_MIN, secondLargest = INT_MIN;
        int smallest = INT_MAX, secondSmallest = INT_MAX;
        
        for (int num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = max(secondLargest, num);
            }
        
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
        }
        return (largest * secondLargest) - (secondSmallest * smallest);
    }
};