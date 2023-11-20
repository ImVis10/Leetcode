class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        
        unordered_map<char, int> truckTravelsTill;
        
        for (int i = 0; i < n; i++) {
            if (garbage[i].find('M') != string::npos) truckTravelsTill['M'] = i;
            if (garbage[i].find('G') != string::npos) truckTravelsTill['G'] = i;
            if (garbage[i].find('P') != string::npos) truckTravelsTill['P'] = i;
        }
        
        int time = 0;
        
        for (auto& [k, v] : truckTravelsTill) {
            for (int i = 0; i <= v; i++) {
                for (char ch : garbage[i]) {
                    if (ch == k) time++;
                }
                if (i != v) time += travel[i];
            }
        }
        return time;
    }
};