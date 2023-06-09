class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        for (char letter : letters) {
            if (letter > target) {
                res = letter;
                break;
            }
        }
        return res;
    }
};