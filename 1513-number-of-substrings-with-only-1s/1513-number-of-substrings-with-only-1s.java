class Solution {
    public int numSub(String s) {
        int mod = (int) Math.pow(10, 9) + 7;
        int res = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            count = s.charAt(i) == '1' ? count + 1 : 0; // increment count whenever a consecutive '1' is found.
            res = (res + count) % mod; // update the no. of substrings traversed till now.
        }
        return res;
    }
}