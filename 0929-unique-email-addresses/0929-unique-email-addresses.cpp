class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // set<string> uniqueEmails;
        // for (string email : emails) {
        //     string localName = email.substr(0, email.find('@'));
        //     localName = localName.substr(0, email.find('+')); // find returns first occurrence of '+'
        //     localName = regex_replace(localName, regex("\\."), "");
        //     string domainName = email.substr(email.find('@') + 1, email.length());
        //     email = localName + '@' + domainName;
        //     uniqueEmails.insert(email);
        // }
        // return uniqueEmails.size();
        
        set<string> uniqueEmails;
        
        for (string email : emails) {
            string cleanEmail;
            for (char ch : email) {
                if (ch == '+' || ch == '@') {
                    break;
                }
                if (ch == '.') {
                    continue;
                }
                cleanEmail += ch;
            }
            cleanEmail += email.substr(email.find('@'));
            cout << cleanEmail << endl;
            uniqueEmails.insert(cleanEmail);
        }
        return uniqueEmails.size();
    }
};