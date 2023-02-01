class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        // scan every row first and reduce the search space to the rows with no. of target black pixels
        // while scanning the rows, get the count of black pixels in each column
        // scan each column and if no. of black pixels == target, add the target black pixels to result
        int res = 0;
        int rows = picture.size(), cols = picture[0].size();
        
        unordered_map<string, int> map;
        vector<int> numBlackPixelsInACol(cols);
        
        for (int i = 0; i < rows; i++) {
            string rowWithTargetBlackPixels = getRowsWithTargetBlackPixels(picture, i, target, numBlackPixelsInACol);
            if (!rowWithTargetBlackPixels.empty()) {
                map[rowWithTargetBlackPixels] += 1;
            }
        }
        
        for (const auto &rowContent : map) {
            if (rowContent.second == target) {
                for (int j = 0; j < cols; j++) {
                    if ((rowContent.first)[j] == 'B' && numBlackPixelsInACol[j] == target) {
                        res += target;
                    }
                }
            }
        }
        return res;
    }

private:
    string getRowsWithTargetBlackPixels(vector<vector<char>>& picture, int row, int target, vector<int>& numBlackPixelsInACol) {
        int cols = picture[0].size();
        int numBlackPixelsInARow = 0;
        string rowContent;
        
        for (int j = 0; j < cols; j++) { // for every column of a row
            if (picture[row][j] == 'B') {
                numBlackPixelsInARow++;
                numBlackPixelsInACol[j]++;
            }
            rowContent += picture[row][j];
        }
        
        if (numBlackPixelsInARow == target) {
            return rowContent;
        }
        return "";
    }
};