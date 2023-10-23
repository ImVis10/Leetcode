class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0; //  turns used by alice and bob
        
        int n = colors.length();
        
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') alice++;
                else bob++;
            }
        }
        return bob < alice;
    }
};