class Solution {
public:
    int totalMoney(int n) {
        int completeWeeks = n / 7;
        int remainingDays = n % 7;
        
        // for each complete week the sum would be in arithematic progression
        // week 1 - 28, week 2 - 35, week 3 - 42
        // so sum for total # weeks can be calculated using the formula of sum of n terms in a arithematic progression
        // n / 2 (first term + nth term)
        // n = completeWeeks, first term = 28, last term => tn = a + (n - 1) * d
        
        int sumAfterCompleteWeeks = (completeWeeks) * (28 + (28 + (completeWeeks - 1) * 7)) / 2;
        
        cout << sumAfterCompleteWeeks;
        
        int startDay = completeWeeks + 1;
        int remainingSum = remainingDays * (startDay + (startDay + (remainingDays - 1) * 1)) / 2;
        
        return sumAfterCompleteWeeks + remainingSum;
    }
};