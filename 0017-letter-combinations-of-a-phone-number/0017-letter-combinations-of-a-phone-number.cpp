class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
          vector<char> cur(digits.length());
          vector<string> res;
          recurse(0, digits, cur, res);
          return res;
    }
private:
    unordered_map<int, vector<char>> map {
      {0, {'0'}},  {1, {'1'}}, {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}
    };

    void recurse(int idx, string ph, vector<char>& cur, vector<string>& res) {
        if (idx == ph.length()) {
          string typedString = accumulate(cur.begin(), cur.end(), string{});
          res.push_back(typedString);
          return;
        }
        
        int typedNum = ph[idx] - '0';
        auto lettersOfNum = map[typedNum];
        
        for (auto letter : lettersOfNum) {
            cur[idx] = letter;
            recurse(idx + 1, ph, cur, res);
        }   
    }
};