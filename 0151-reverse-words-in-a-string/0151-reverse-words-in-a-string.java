class Solution {
    public String reverseWords(String s) {
        String[] words = s.split("\\s+"); // splits the string for one or multiple spaces.
        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            sb.append(words[i]).append(" ");
        }
        return sb.toString().trim();
    }
}