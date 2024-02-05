class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        for (int i = 1; i <= 9; i++) {
            int num = i;
            int nextDigit = i + 1;
            while (num <= high and nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (num >= low and num <= high) {
                    res.push_back(num);
                }
                nextDigit++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};