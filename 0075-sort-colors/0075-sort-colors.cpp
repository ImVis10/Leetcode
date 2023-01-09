class Solution {
public:
    void sortColors(vector<int>& nums) {
        // in-place sorting
        // can do bucket sort
        vector<int> res;
        int n = nums.size();
        
        int numZero = 0, numOne = 0, numTwo = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                numZero++;
            } else if (nums[i] == 1) {
                numOne++;
            } else {
                numTwo++;
            }
        }
        
        nums.clear();
        
        for(int i = 0; i < numZero; i++) {
            nums.emplace_back(0);
        }
        
        for(int i = 0; i < numOne; i++) {
            nums.emplace_back(1);
        }
        
        for(int i = 0; i < numTwo; i++) {
            nums.emplace_back(2);
        }
    }
// private:
//     void swap(int num1, int num2) {
//         int temp = num1;
//         num1 = num2;
//         num2 = temp;
//     }
};