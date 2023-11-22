class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        int res = 0, mod = 1e9 + 7;
        
        for (int num : nums) {
            int val = num - rev(num);
            if (mp.find(val) != mp.end()) res = (res + mp[val]) % mod;
            mp[val]++;
        }
        return res;
    }
    
    int rev(int num) {
        int res = 0;
        while (num) {
            int rem = num % 10;
            res  = rem + res * 10;
            num /= 10;
        }
        return res;
    }
};