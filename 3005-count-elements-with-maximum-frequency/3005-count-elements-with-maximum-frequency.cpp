class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxFreq = 0;
        for (auto[num, cnt] : freq) {
            maxFreq = max(cnt, maxFreq);
        }
        int numMaxFreq = 0;
        for (auto [num, cnt] : freq) {
            if (cnt == maxFreq) numMaxFreq++;
        }
        return maxFreq * numMaxFreq;
    }
};