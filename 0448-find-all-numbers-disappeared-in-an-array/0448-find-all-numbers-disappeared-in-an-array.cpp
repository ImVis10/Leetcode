class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> res;
        
//         int n = nums.size();
        
//         set<int> set;
        
//         for(int num : nums) {
//             set.insert(num);
//         }
        
//         for (int i = 1; i <= n; i++) {
//             if(!set.count(i)) {
//                 res.push_back(i);
//             }
//         }
//         return res;
        // WITHOUT USING EXTRA SPACE
        // IDEA: MUTATE THE INPUT ARRAY TO INDICATE WHETHER THE NUMBER IS PRESENT IN THE ARRAY
        // SINCE ALL THE ELEMENTS ARE IN THE RANGE [1, N]
        // -VE SIGN INDICATES THAT THE NUMBER IS PRESENT IN THE ARRAY
        // WE CAN CHANGE THE SIGN OF LET'S SAY ELEMENT AT POSITION 2 ONLY WHEN THERE IS 3 IN THE ARRAY
        // TO GENERALIZE WE CAN SAY THAT THE ELEMENT i IS PRESENT IN THE ARRAY ONLY WHEN THE SIGN OF ELEMENT AT INDEX i - 1 IS -VE
        vector<int> res;
        int n = nums.size();
        
        for (int  i = 0; i < n; i++) {
            int gg = abs(nums[i]) - 1;
            if (nums[gg] > 0) {
                nums[gg] *= - 1;
            }
        }
        
        for (int  i = 1; i <= n; i++) {
            if (nums[i - 1] > 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};