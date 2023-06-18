class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char, int> map;
        for (char ch : s) {
            map[ch]++;
        }
        
        auto maxVal = max_element(map.begin(), map.end(), [](const auto& x, const auto& y) {
            return x.second < y.second;
        });
        
        vector<vector<char>> buckets(maxVal->second + 1);
        
        for (auto& entry : map) {
            int freq = map[entry.first];
            buckets[freq].push_back(entry.first);
        }
        
        for (int i = buckets.size() - 1; i > 0; i--) {
            for (char ch : buckets[i]) {
                for (int j = 0; j < i; j++) {
                    res += ch;
                }
            }
        }
        return res;
    }
};