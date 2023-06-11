class Solution {
public:
    string largestOddNumber(string num) {
        // start from the end
        int n = num.length();
        
        for (int i = n - 1; i >= 0; i--) {
            if (!(num[i] & 1)) { // if the digit is even
                num.pop_back();
            } else {
                break;
            }
        }
        return num;
    }
};