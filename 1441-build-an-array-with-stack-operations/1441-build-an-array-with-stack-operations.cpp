class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        
        int len = target.size();
        int idx = 0;
        
        vector<string> res;
        
        for (int num = 1; num <= n; num++) {
            if (idx == len) break;
            if(target[idx] == num) {
                res.push_back("Push");
                idx++;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};