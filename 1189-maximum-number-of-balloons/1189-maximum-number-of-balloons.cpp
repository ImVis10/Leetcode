class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res = text.length(); // or INT_MAX also works
        map<char, int> mapText;
        for (char ch : text) {
            mapText[ch]++;
        }
        
        string balloon = "balloon";
        map<char, int> mapBalloon;
        for (char ch : balloon) {
            mapBalloon[ch]++;   
        }
        
        for (char ch : balloon) {
            res = min(res, mapText[ch] / mapBalloon[ch]);
        }
        
        return res;
    }
};