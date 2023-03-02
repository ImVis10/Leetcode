class Solution {
public:
    int compress(vector<char>& chars) {
        int res= 0;
        int i = 0;
        
        while (i < chars.size()) {
            int groupLength = 1; // minimum group length is 1
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength += 1;
            }
            
            chars[res] = chars[i];
            res += 1;
            
            if (groupLength > 1) {
                for (char ch : to_string(groupLength)) {
                    chars[res] = ch;
                    res += 1;
                }
            }
            
            i += groupLength;
        }
        return res;
    }
};