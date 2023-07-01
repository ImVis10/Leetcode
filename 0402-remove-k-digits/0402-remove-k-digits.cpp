class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == 0) {
            return num;
        }
        
        if (k >= num.length()) {
            return "0";
        }
        
        string res = "";
        for (char digit : num) {
            while (res.size() > 0 && res.back() > digit && k > 0) {
                res.pop_back();
                k--;
            }
            if (!(res.size() == 0 && digit == '0')) {
                res.push_back(digit);
            }
        }
        
        while (res.size() > 0 && k--) {
            res.pop_back();
        }
        return (res == "") ? "0" : res;
    }
};