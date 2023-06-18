class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char, int> map;
        for (char ch : s) {
            map[ch]++;
        }
        
        vector<pair<char, int>> A;

        for (auto& it : map) 
            A.push_back(it);

        sort(A.begin(), A.end(), cmp);
        
        for (auto& entry : A) {
            while (entry.second--) {
                res += entry.first;
            }
        }
        return res;
    }
    
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }
  
};