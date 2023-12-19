class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        // vector<vector<int>> res(m, vector<int>(n));
        
        // solution optimized for space : got from the editorial
        // we have a constraint that each element is going to be in the range of 0 - 255
        // so it can take at the max 8 bits of integer, but size of integer is 32 in c++ (and most programming languages)
        // we can make use of this fact and the extra space
        // for smoothening of every cell, we need the surrounding cells. But if we modify the number entrirely, we'll get invalid smoothing value for the other cells (as this cell's value is changed)
        // we can make use of the extra 23 bits we have (MSB is excluded as it is a sign bit), but this space would be more than enough as the average of the numbers would be in the range of 0 - 255, so 8 bits would suffice
        // sign bit, zeros, smoothing value, actual value would be the structure of the number 
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int sum = 0, cnt = 0;
                for (int i = row - 1; i <= row + 1; i++) {
                    for (int j = col - 1; j <= col + 1; j++) {
                        if (i < 0 or i >= m or j < 0 or j >= n) continue;
                        int last8Bits = img[i][j] & 255; // 255 is only 8 bits, so we get least significant 8 bits
                        sum += last8Bits; 
                        cnt += 1;
                    }
                }
                int smoothingValue = (sum / cnt) << 8;
                img[row][col] |= smoothingValue;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }
        return img;
    }
 };