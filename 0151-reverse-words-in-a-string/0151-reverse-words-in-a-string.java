class Solution {
    // public String reverseWords(String s) {
    //     String[] words = s.split("\\s+"); // splits the string for one or multiple spaces.
    //     StringBuilder sb = new StringBuilder();
    //     for (int i = words.length - 1; i >= 0; i--) {
    //         sb.append(words[i]).append(" ");
    //     }
    //     return sb.toString().trim();
    // }

    /** Took from comment section, no extra space used.**/
    public String reverseWords(String s) {
        if (s.length() < 1) return s; // empty string
        int startIdx = 0;
        char[] str = s.toCharArray();
        // reverse whole string
        reverse(str, 0, str.length - 1);
        // reverse word one by one
        for (int i = 0; i < str.length; i++) {
            if (str[i] != ' ') {
                if (startIdx != 0) {
                 str[startIdx++] = ' ';  // put a space at the beginning of a word. 
                } 
                int j = i;
                while (j < str.length && str[j] != ' ') { // get the entire word until a space arrives.
                    str[startIdx++] = str[j++];
                }   
                reverse(str, startIdx - (j - i), startIdx - 1); // reverse the word
                i = j;
            }
        }
        return new String(str, 0, startIdx);
    }

    private void reverse(char[] str, int start, int end) {
        for (; start < end; start++, end--) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
        }
    }
}