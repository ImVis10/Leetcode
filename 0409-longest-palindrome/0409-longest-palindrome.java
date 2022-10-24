class Solution {
    public int longestPalindrome(String s) {
        // Note: Letters are case sensitive
        /** Intuition: For a string to be a palindrome, each character should have its replica at the other end (like when looked from a mirror), at the other end of the middle element. But our scenario is not to check if the given string is a palindrome, but to find the length of the longest palindrome that can be made using the given string. So if each char has its corresponding pair and if there is a unique element that can sit in the middle (here it can have 2 instances as well, they can sit in the middle or at the end of each side, etc). It seems that set might be a useful data structure for this**/
        if (s.length() == 1) {
            return 1;
        }
        
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            if (set.contains(s.charAt(i))) {
                set.remove(s.charAt(i)); // if the char is already present in set, remove it. So that we know there is a pair.
            } else {
                set.add(s.charAt(i)); // if a char is not present in the set, add it to the set.
            }
        }
        int pickOneFromSetIfItHasAny = set.isEmpty() ? 0 : 1; // If set has multiple chars, take one char from it. 
        return s.length() - set.size() + pickOneFromSetIfItHasAny; //subtract the size of the set and pick one from the set if it has multiple chars
    }
}