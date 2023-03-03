class Solution {
public:
    int strStr(string haystack, string needle) {
        // check if needle is part of the haystack
        // if not, return -1
        // if yes, return the start index of first occurrence of needle in the haystack
        
        int res = -1;
        
        int startPos = 0;
        
        int needleSize = needle.size();
        int haystackSize = haystack.size();
        
        while (startPos < haystackSize) {
            auto goTofirstOcc = find(haystack.begin() + startPos, haystack.end(), needle[0]);
            int firstOccAt = goTofirstOcc - haystack.begin();
            string expectedNeedle = haystack.substr(firstOccAt, needleSize);
            
            if (expectedNeedle == needle) {
                res = firstOccAt;
                break;
            } else {
                startPos += 1;
                continue;
            }            
        }
        return res;
    }
};