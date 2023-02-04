class Solution {
            // hashmap(char, string) to store num and its associated chars.
        // 2 to 9 - nums
        // naive way:
        /**
        for each key in the map, iterate through all the possible combinations with its associated
        string's chars.
        This takes O(n^2) and maybe more. Lets see if we can do this in something less than that
        **/
        // This seems like this can be solved using DFT.
            char[][] chars = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},      {'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    public List<String> letterCombinations(String digits) {
        int len = digits.length();
        List<String> res = new ArrayList<>();
        if (digits.length() == 0) {
            return res;
        }
        dfs(0, len, new StringBuilder(), res, digits);
        return res;
        
    }
    
    private void dfs(int pos, int len, StringBuilder sb, List<String> res, String digits) {
        if (len == pos) {
            res.add(sb.toString()); // if len == pos, it means the no. of chars in a combination have reached the limit and the combination string must be added to the result list.
        } else {
            // how to get the index here? What all do we have at our disposal?
            char[] charsInCurrPos = chars[Character.getNumericValue(digits.charAt(pos))];
            for (Character c : charsInCurrPos) {
                // dfs on each character. Incrementing the position by 1
                dfs(pos + 1, len, new StringBuilder(sb).append(c), res, digits);
            }
        }
    }
}