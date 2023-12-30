class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        
        vector<int> freq(26);
        
        for (string word : words) {
            for (char ch : word) {
                freq[ch - 'a']++;
            }
        }
        
        for (int cnt : freq) {
            if (cnt % n) return false;
        }
        return true;
    }
};