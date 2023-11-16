class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        set<string> set(nums.begin(), nums.end());
        genBin(n, set, res, false);
        return res;
    }
private:
    void genBin(int n, set<string>& set, string& res, bool found, string s = "") {
        if (found) return;
        if (s.length() == n) {
            if (set.find(s) == set.end()) {
                res = s;
                found = true;
            }
            return;
        }
        genBin(n, set, res, found, s + '0');
        genBin(n, set, res, found, s + '1');
    }
};