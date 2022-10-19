class Solution {
    public boolean isSubsequence(String s, String t) {
        int sLen = s.length(), tLen = t.length();
        int i = 0, j = 0;
        while (i < sLen && j < tLen) {
            if(s.charAt(i) == t.charAt(j)) {
                i++; // if char in s == char in t, move to next char in s
            }
            j++; // move to next char in t to check with each char of t
        }
        return i == sLen; // if all chars in s are visited and all of them are in the same order as in t, then it is a subsequence. If not, then it is not a sub sequence.
    }
}