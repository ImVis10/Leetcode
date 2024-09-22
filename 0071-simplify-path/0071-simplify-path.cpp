class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string str, res = "";
        vector<string> stk;
        while(getline(ss, str, '/')) { // split string based on '/'
            if (str == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (str != "." and !str.empty()) {
                stk.push_back(str);
            }
        }
        
        for (string& s : stk) {
            res += '/' + s;
        }
        
        return res.empty() ? "/" : res;
    }
};