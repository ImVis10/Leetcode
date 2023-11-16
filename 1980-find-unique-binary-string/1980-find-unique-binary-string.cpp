class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        set<string> set(nums.begin(), nums.end());
        genBin(n, set, res);
        return res;
    }
private:
    void genBin(int n, set<string>& set, string& res, string s = "") {
        if (s.length() == n) {
            if (set.find(s) == set.end()) {
                res = s;
            }
            return;
        }
        genBin(n, set, res, s + '0');
        genBin(n, set, res, s + '1');
    }
};