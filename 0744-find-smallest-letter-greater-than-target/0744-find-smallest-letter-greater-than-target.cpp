class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // char res = letters[0];
        // for (char letter : letters) {
        //     if (letter > target) {
        //         res = letter;
        //         break;
        //     }
        // }
        // return res;
        
        // The above approach takes O(n), but we can make use of binary search as the array is already sorted
        char res = letters[0];
        int low = 0, high = letters.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target) {
                high = mid - 1;
                res = letters[mid];
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};