class Solution {
public:
    bool buddyStrings(string s, string goal) {
//         if (goal.length() != s.length() || s.length() == 1) {
//             return false;
//         }
        
//         string temp = s;
        
//         for (int i = 0; i < s.length() - 1; i++) {
//             for (int j = i + 1; j < s.length(); j++) {
//                 swap(s[i], s[j]);
//                 if (s == goal) {
//                     return true;
//                 }
//                 s = temp;
//             }
//         }
//         return false;
        
        if (goal.length() != s.length() || s.length() == 1) {
            return false;
        }
        
        if (s == goal) {
            set<char> set(s.begin(), s.end());
            return set.size() < goal.size();
        }
        
        int l = 0, r = s.length() - 1;
        
        while (l < r && s[l] == goal[l]) {
            l++;
        }
        
        while (r >= 0 && s[r] == goal[r]) {
            r--;
        }
        
        if (l < r)
            swap(s[l], s[r]);
        
        return s == goal;
    }
};