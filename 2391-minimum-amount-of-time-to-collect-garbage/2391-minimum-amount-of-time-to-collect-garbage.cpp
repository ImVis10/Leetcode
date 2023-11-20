class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        
        unordered_map<char, int> lastHouseForGarbage;
        
        unordered_map<char, int> totalGarbage;
        
        for (int i = 0; i < n; i++) {
            for (char ch : garbage[i]) {
                lastHouseForGarbage[ch] = i;
                totalGarbage[ch]++;
            }
        }
        
        vector<int> timeToTravelTill(n);
        
        for (int i = 1; i < n; i++) {
            timeToTravelTill[i] = timeToTravelTill[i - 1] + travel[i - 1];
        }
        
        int time = 0;
        
        for (auto& [garbageType, lastHouse] : lastHouseForGarbage) {
            time += totalGarbage[garbageType] + timeToTravelTill[lastHouse];
        }
        return time;
    }
};