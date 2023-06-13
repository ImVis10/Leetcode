class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
//         int numRows = grid.size();
//         int numCols = numRows;
        
//         int cnt = 0;
        
//         for (int i = 0; i < numRows; i++) {
//             for (int j = 0; j < numCols; j++) {
//                 bool isEqual = true;
                
//                 for (int k = 0; k < numRows; k++) {
//                     if (grid[i][k] != grid[k][j]) {
//                         isEqual = false;
//                         break;
//                     }
//                 }
                
//                 cnt += isEqual ? 1 : 0;
//             }
//         }
//         return cnt;
        
        // BETTER APPROACH - USING HASHING O(n^2)
        int n = grid.size();
        int cnt = 0;
        
        map<string, int> map;
        for (auto& row: grid) {
            // CAN'T DO THIS.. GOTTA HAVE COMMAS AS [[11,1],[1,11]] ==> 111 AND 111. BUT BOTH THE ENTRIES ARE NOT THE SAME ONE IS [11, 1] AND OTHER IS [1, 11]
            // ostringstream oss;
            // copy(row.begin(), row.end(), ostream_iterator<int>(oss));
            // string rowStr = oss.str();
            string rowStr = join(row, ",");
            map[rowStr] += 1;
        }
        
        for (int i = 0; i < n; i++) {
            vector<int> colArray(n);
            for (int j = 0; j < n; j++) {
                colArray[j] = grid[j][i];
            }
            cnt += map[join(colArray, ",")];
        }
        return cnt;
    }
    
private:
    string join(vector<int> const &vec,string delim) {
    if (vec.empty()) {
        return string();
    }
 
    return accumulate(vec.begin() + 1, vec.end(), 
    to_string(vec[0]),
                [](const string& a, int b){
                    return a + ", " + to_string(b);
                });
    }
};