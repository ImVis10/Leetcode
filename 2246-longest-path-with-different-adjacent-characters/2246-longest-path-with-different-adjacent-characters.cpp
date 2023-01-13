class Solution {
    // TOOK SOLUTION FROM SOLUTION SECTION

public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        
        int longestPath = 1;
        dfs(0, children, s, longestPath);
        
        return longestPath;
    }
    
private:
    int dfs(int node, vector<vector<int>>& children, string& s, int& longestPath) {
        int longestChain = 0, secondLongestChain = 0; // longest and second longest chains across all the children of node
        for (int child : children[node]) {
            int longestPathStartingFromChild = dfs(child, children, s, longestPath);
            
            if (s[child] == s[node]) { // if adjacent characters are the same, don't include them in the chain. Just continue
                continue;
            }
            
            if (longestPathStartingFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestPathStartingFromChild;
            } else if (longestPathStartingFromChild > secondLongestChain) {
                secondLongestChain = longestPathStartingFromChild;
            }
        }
        
        longestPath = max(longestPath, 1 + longestChain + secondLongestChain);
        return 1 + longestChain;
    }
};