class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        split(words, separator, res);
        // res.erase(remove_if(res.begin(), res.end(), [](const auto& s) {
        //     return s.empty();
        // }),
        // res.end());
        return res;
    }
private:
    void split(vector<string>&words, char sep, vector<string>& res) {
        for (auto& w : words) {
            int i = 0;
            int start = 0, end = 0;
            while (i <= w.length()) {
                if (w[i] == sep || i == w.length()) {
                    end = i;
                    string subStr = "";
                    subStr.append(w, start, end - start);
                    if (subStr != "") res.push_back(subStr);
                    start = end + 1;
                }
                i++;
            }
        }
    }
};