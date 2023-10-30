class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int cntA = numOneBits(a);
            int cntB = numOneBits(b);
            return (cntA != cntB) ? cntA < cntB : a < b;
        });
        return arr;
    }
private:
    int numOneBits(int num) {
        int cnt = 0;
        
        while (num) {
            cnt++;
            num &= (num - 1);
        }
        return cnt;
    }
};