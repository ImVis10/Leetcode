class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        set<int> set;
        
        for (int num : arr) freq[num]++;
        
        for (auto&[num, cnt] : freq) set.insert(cnt);
        
        return set.size() == freq.size();
    }
};