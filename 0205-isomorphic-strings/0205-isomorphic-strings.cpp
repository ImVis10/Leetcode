// JAVA
// class Solution {
//     public boolean isIsomorphic(String s, String t) {
//         int len1 = s.length(), len2 = t.length();
//         if (len1 != len2) {
//             return false;
//         }
//         Map<Character, Integer> map1 = new HashMap<>();
//         Map<Character, Integer> map2 = new HashMap<>();
//         for (int i = 0; i < len1; i++) {
//             int idx1 = map1.getOrDefault(s.charAt(i), -1);
//             int idx2 = map2.getOrDefault(t.charAt(i), -1);
            
//             if (idx1 != idx2) {
//                 return false;
//             }
//             // updating the value in the map to the index everytime the char is encountered. If the corresponding chars are at the appropriate position like in isomorphic strings, entire strings are iterated and then returned true
//             map1.put(s.charAt(i), i);
//             map2.put(t.charAt(i), i);
//         }
//         return true;
        
//     }
// }

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        return checkTwice(s, t) && checkTwice(t, s);
    }

private:
    bool checkTwice(string s, string t) {
        map<char, char> map;
        
        for (int  i = 0; i < s.length(); i++) {
            if (!map.count(s[i])) {
                map[s[i]] = t[i];
            } else if (map[s[i]] == t[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};