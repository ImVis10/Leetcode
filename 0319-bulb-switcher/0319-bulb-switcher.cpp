class Solution {
public:
    int bulbSwitch(int n) {
        
//         vector<int>arr(n + 1, 0);
        
//         int round = 1;
        
//         while (round <= n) {
//             for (int i = 1; i <= n; i++) {
//                 if (round == 1 || i % round == 0) {
//                     arr[i] = 1 - arr[i];                    
//                 }
//             }
//             round++;
//         }
        
//         int res = std::count(arr.begin(), arr.end(), 1);
//         return res;
        
        // ALL BULBS ARE INITIALLY OFF.
        // AT THE END, ONLY THE BULBS THAT ARE TOGGLED ODD NO. OF TIMES WILL REMAIN ON.
        
        // A PERFECT SQUARE NUMBER WILL HAVE ODD NUMBER OF FACTORS
        // EG: 25 = 5 * 5. FACTORS OF 25 = 1, 5, 25. #FACTORS OF 25 = 3
        
        // SO JUST TO FIND OUT HOW MANY NUMBERS BETWEEN 1 AND n ARE PERFECT SQUARES
        // WHICH IS NOTHING BUT FLOOR(SQRT(n))
        // EG: n = 17, PERFECT SQUARES = 1, 4, 9, 16, #PERFECT SQUARES = 4 i.e. FLOOR(SQRT(17))
        
        return sqrt(n);
        
    }
};