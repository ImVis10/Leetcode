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
        
        // Do bucket sort
        // BUCKET SORT IS NOT A SORTING ALGO BASED ON COMPARISON.. SO IT TAKES O(n) not O(n log n)
        // Number of buckets is equal to the maximum frequency + 1
        // +1 because it is 0-indexing
        vector<vector<char>> buckets(maxVal->second + 1);
        
        
        // allocate chars for each bucket
        // eg: TREE
        // 0   1     2
        //  {E, E}  {T}
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