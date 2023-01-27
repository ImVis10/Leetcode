class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int currSum = 0;
            for (int j = i; j < arr.size(); j++) {
                currSum += arr[j];
                res += (j - i + 1) & 1 == 1 ? currSum : 0;
            }
        }
        return res;
    }
};