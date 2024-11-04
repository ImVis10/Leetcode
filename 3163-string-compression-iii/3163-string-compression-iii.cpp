class Solution {
public:
    string compressedString(string word) {
        /**
        aaaaaaaaaaaaaabb
        123456789abcde    
        9a5a1b1c1d1e
        **/
        string comp;
        int n = word.length();
        for (int i = 0, j = 0; j < n; j++) {
            if (j == n - 1 or word[j] != word[j + 1] or j - i + 1 == 9) {
                cout << word[j + 1] << endl;
                comp += to_string(j - i + 1);
                comp += word[j];
                i = j + 1;
            }
        }
        return comp;
    }
};