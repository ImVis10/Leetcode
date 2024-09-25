class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        sort(numStrings.begin(), numStrings.end(), [](string& s1, string& s2) {
           return s1 + s2 > s2 + s1; 
        });
        
        string res;
        for (string num : numStrings) res += num;
        return res[0] == '0' ? "0" : res;
    }
};