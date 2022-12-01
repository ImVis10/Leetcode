class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        Map<Character, Integer> map = new HashMap<>(); // to store frequency of characters
        int i = 0; // sliding window left pointer
        for (int j = 0; j < s.length(); j++) { // right pointer of sliding window
            char endOfWindow = s.charAt(j);
            map.put(endOfWindow, map.getOrDefault(endOfWindow, 0) + 1);
            while (map.get(endOfWindow) > 1) { // when not valid window
                char startOfWindow = s.charAt(i);
                map.put(startOfWindow, map.get(startOfWindow) - 1); // make it valid by incrementing the left pointer and decreasing the char's(which is repeating) count as well
                i++;
            }
            res = Math.max(res, j - i + 1); // update length of the valid substring(in the question's context)
            // Taking max as we need length of the largest valid substring
        }
        return res;
    }
}