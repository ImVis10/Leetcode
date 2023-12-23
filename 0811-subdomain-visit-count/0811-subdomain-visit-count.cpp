class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        
        for (string domain : cpdomains) {
            int visits = stoi(domain.substr(0, domain.find(' ')));
            int len = domain.length();
            for (int i = len - 1; domain[i] != ' '; i--) {
                if (domain[i] == '.' || domain[i - 1] == ' ') {
                    string subdomain = domain.substr(i + (domain[i - 1] != ' '), len - i);
                    mp[subdomain] += visits;
                }
            }
        }
        
        vector<string> res;
        
        for (auto& [domain, count] : mp) {
            res.push_back(to_string(count) + ' ' + domain);
        }
        return res;
    }
};