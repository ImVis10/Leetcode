class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        stack<string> stk;
        
        for (auto& s : folder) {
            if (!stk.empty() and stk.top() == s.substr(0, stk.top().length()) and isalpha(s[stk.top().length() + 1])) {
                continue;
            } else {
                stk.push(s);
            }
        }
        
        vector<string> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};