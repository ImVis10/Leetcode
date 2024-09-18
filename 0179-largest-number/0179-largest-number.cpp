class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int num : nums) s.push_back(to_string(num));
        
        sort(s.begin(), s.end(), [](string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        
        if(s[0] == "0") return "0";
        
        string res = "";
        
        for (string str : s) res += str;
        return res;
    }
};