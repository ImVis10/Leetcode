class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    /**
    given two nums a, b
    if a % k == x and b % k == k - x, then (a + b) % k == 0
    proof : (a + b) % k = ((a + b) % k) % k = (a % k + b % k) % k = (x + k - x) % k = k % k = 0
    **/
        vector<int> freq(k); // frequency of rems
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) rem += k;
            freq[rem]++;
        }
        if (freq[0] % 2) return false; // number of nums perfectly divisible by k must be even
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        return true;
    }
};