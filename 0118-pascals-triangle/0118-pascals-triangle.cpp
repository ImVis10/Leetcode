class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /**1---> [0, 0]
          1 1 --> [1,0],  [1, 1]
         1 2 1 --> [2, 0], [2, 1] = [1, 0] + [1, 1], [2, 2]
        1 3 3 1 -- > [3, 0], [3, 1] = [2, 0] + [2, 1], [3, 2] = [2, 1] + [2, 2], [3, 3]
       1 4 6 4 1
       **/
        // row[j] = res[i - 1][j - 1] + res[i - 1] + [j], 1 <= j < i, 0 < i < numRows
        vector<vector<int>> res;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.emplace_back(row);
        }
        return res;
    }
};