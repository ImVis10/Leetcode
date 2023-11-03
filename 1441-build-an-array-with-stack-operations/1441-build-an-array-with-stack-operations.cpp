class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        int idx = 0;
        
        vector<string> res;
        
        for (int num = 1; num <= n; num++) {
            if (idx == len) break;
            res.push_back("Push");
            if(target[idx] == num) idx++;
            else res.push_back("Pop");
        }
        return res;
    }
};