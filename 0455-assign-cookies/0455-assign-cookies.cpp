class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        int numChild = g.size(), numCookies = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        
        while (i < numChild and j < numCookies) {
            if (s[j] >= g[i])  {
                i++; 
                res++;
            }
            j++;
        }
        return res;
    }
};