class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // check if each element is an anagram of the other and group them accordingly.
        // is this efficient? Nah.. checking if two strings are anagrams would take O(n), so lets say for K strings and group them together would take around O(nk) I guess
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end()); // sort the string in the increasing order of its characters
            map[strs[i]].push_back(str); // key(sorted_String) --> value(initial _string);
        }
        
        for (auto i = map.begin(); i != map.end(); i++) {
            res.push_back(i -> second); // adding the list of anagrams to result
        }
        return res;
    }
};