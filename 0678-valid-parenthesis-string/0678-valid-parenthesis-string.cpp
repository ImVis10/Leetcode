class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        // count number of ')' we are waiting for
        // it should be equl to number of open parenthesis
        // but since we have a special character * as well, * can be read as '(', ')' or ""
        // so it will be in the range [minOpen, maxOpen]
        
        // minOpen - minimum number of open parenthesis that must be paired
        // maxOpen - maximum number of open parenthesis that could be paired
        
        // say we have passed (*( in a string, minimum # open parenthesis that must be paired should be 1, as (* would be balanced if * can be considered as ), maximum # open parenthesis that could be paired is 3, if * is (
        
        for (char ch : s) {
            if (ch == '(') {
                minOpen++;
                maxOpen++;
            } else if (ch == ')') {
                minOpen = max(minOpen - 1, 0);
                maxOpen--;
            } else {
                minOpen = max(minOpen - 1, 0);
                maxOpen++;
            }
            if (maxOpen < 0) return false;
        }
        return minOpen == 0;
    }
};