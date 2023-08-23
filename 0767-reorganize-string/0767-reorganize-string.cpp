class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char, int> freq;
        
        for (char ch : s) {
            freq[ch]++;
        }
        
        // sort the map in descending order based on the char's count
//         vector<pair<char, int>> freq(map.begin(), map.end());
//         sort(freq.begin(), freq.end(), customSort);
        
        // heap would be better I guess, as we need the character with the most frequency in every iteration. Iterating though the map everytime would be a costly affair.
        
        // Custom comparator to compare the second elements of pairs for max heap
        auto comparator = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
    
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comparator)> pq(comparator);

        // Insert into the max heap
        for (auto& entry : freq) {
            pq.push(entry);
        }
        
        // KEY IDEA: POP TWO ELEMENTS IN EACH ITERATION
        while (pq.size() >= 2) {
            pair<char, int> p1 = pq.top();
            pq.pop();
            
            pair<char, int> p2 = pq.top();
            pq.pop();
            
            res += p1.first;
            res += p2.first;
            
            if (--p1.second) pq.push({p1.first, p1.second});
            if (--p2.second) pq.push({p2.first, p2.second});
        }
        
        if (!pq.empty()) { // IF not WHILE since by this point, pq would have only 1 element
            pair<char, int> p = pq.top();
            if (p.second > 1) return "";
            res += p.first;
        }
        return res;
    }
};