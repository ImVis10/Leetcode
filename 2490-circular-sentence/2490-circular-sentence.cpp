class Solution {
public:
    bool isCircularSentence(string sentence) {
        string firstStr, prevStr, currStr;
        stringstream ss(sentence);
        int cnt = 0;
        while (getline(ss, currStr, ' ')) {
            if (cnt == 0) firstStr = currStr;
            if (cnt != 0 and prevStr[prevStr.length() - 1] != currStr[0]) return false;
            cnt++;
            prevStr = currStr;
        }
        return firstStr[0] == currStr[currStr.length() - 1];
    }
};