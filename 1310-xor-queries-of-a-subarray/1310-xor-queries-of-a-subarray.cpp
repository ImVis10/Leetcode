class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> res;
        // to avoid repetitive work, we can use the prefix xor logic
        // just like prefixSum, calculate prefix xor for the array
        // this is helpful because of the fact that val ^ val = 0
        // say i have the array [1,3,4,8] and I want the xor of values from idx 1 to 3
        // i.e. 3^4^8.. in the prefix xor array we'll have [1, 1 xor 3, 1 xor 3 xor 4, 1 xor 3 xor 4 xor 8]
        // to get arr[1] .. ^ arr[3]  = 3^4^8 = (1 xor 3 xor 4 xor 8) xor 1 = prefixXor[3] ^ prefixXor[1 - 1]
        // we can generalize this to prefixXor[j] - prefixXor[i - 1]
        // when i  = 0, it's just prefixXor[j]
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];
        }
        
        for (auto& vec : queries) {
            int i = vec[0], j = vec[1];
            res.push_back(i == 0 ? arr[j] : arr[j] ^ arr[i - 1]);
        }
        return res;
    }
};