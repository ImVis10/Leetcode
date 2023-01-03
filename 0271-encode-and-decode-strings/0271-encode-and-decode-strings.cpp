class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString;
        for (auto &str : strs) {
            char temp[4];
            int len = str.length();
            memcpy(temp, &len, sizeof(int));
            for (auto ch : temp) {
                encodedString += ch;
            }
            encodedString += str;
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int pos = 0;  
        vector<string> decodedStrings;
        while (pos < s.length()) {
            int len;
            memcpy(&len, &s[pos], sizeof(int));
            pos += sizeof(int);
            decodedStrings.push_back(s.substr(pos, len));
            pos += len;
        }
        return decodedStrings;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));