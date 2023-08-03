//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        if (m[0][0] == 1) {
            recurse(0, 0, m, n, visited, "", res);
        }
        return res;
    }
    private:
    void recurse(int row, int col, vector<vector<int>>& m, int n, vector<vector<bool>>& visited, string path, vector<string>& res) {
        if (row == n - 1 && col == n - 1) {
            res.push_back(path);
            return;
        }
        
        if (row + 1 < n && !visited[row + 1][col] && m[row + 1][col] == 1) { // DLRU as is it in alphabetical order and we need paths in lexicographical order
            visited[row][col] = true;
            recurse(row + 1, col, m, n, visited, path + 'D', res);
            visited[row][col] = false; // backtrack
        }
        
        if (col - 1 >= 0 && !visited[row][col - 1] && m[row][col - 1] == 1) {
            visited[row][col] = true;
            recurse(row, col - 1, m, n, visited, path + 'L', res);
            visited[row][col] = false;
        }
        
        if (col + 1 < n && !visited[row][col + 1] && m[row][col + 1] == 1) {
            visited[row][col] = true;
            recurse(row, col + 1, m, n, visited, path + 'R', res);
            visited[row][col] = false;
        }
        
        if (row - 1 >= 0 && !visited[row - 1][col] && m[row - 1][col] == 1) {
            visited[row][col] = true;
            recurse(row - 1, col, m, n, visited, path + 'U', res);
            visited[row][col] = false;
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends