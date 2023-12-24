class Solution {
public:
    string reformatDate(string date) {
        vector<string> str = splitString(date);
        string day = str[0], month = str[1], year = str[2];
        day = removeAlpha(day);
        day = day.size() == 1 ? '0' + day : day;
        month = monthMap[month];
        string res = year + '-' + month + '-' + day;
        return res;
    }
private:
    unordered_map<string,string> monthMap = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    
    vector<string> splitString(string date) {
        vector<string> res;
        string s = "";
        for (int i = 0; i < date.length(); i++) {
            if (date[i] == ' ') {
                res.push_back(s);
                s = "";
            } else if (i == date.length() - 1) {
                s += date[i];
                res.push_back(s);
            } else {
                s += date[i];
            }
        }
        return res;
    }
    
    string removeAlpha(string day) {
        string s = "";
        for (char ch : day) {
            if (isdigit(ch)) s += ch;
        }
        return s;
    }
};