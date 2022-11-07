class Solution {
    public String longestCommonPrefix(String[] strs) {
        String commonPrefix = strs[0];
        for (int i = 1; i < strs.length; i++) {
            while(strs[i].indexOf(commonPrefix) != 0) {
                commonPrefix = commonPrefix.substring(0, commonPrefix.length() - 1);
            }
        }
        return commonPrefix;
    }
}