class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> stk;
        vector<int> res(n);
        int prevTs = 0, runtime = 0;
        for (string& log : logs) {
            vector<string> stuff = getStuff(log);
            int id = stoi(stuff[0]);
            string type = stuff[1];
            int ts = stoi(stuff[2]);
            if (type == "start") {
                if (!stk.empty()) {
                    runtime = ts - prevTs;
                    res[stk.top()] += runtime;
                } 
                stk.push(id);
                prevTs = ts;
            } else {
                id = stk.top();
                stk.pop();
                runtime = ts - prevTs + 1;
                res[id] += runtime;
                prevTs = ts + 1;
            }
        }
        return res;
    }
private:
    vector<string> getStuff(string& s) {
        vector<string> res;
        stringstream ss(s);
        char delim = ':';
        string temp;
        while (getline(ss, temp, delim)) {
            res.push_back(temp);
        }
        return res;
    } 
};