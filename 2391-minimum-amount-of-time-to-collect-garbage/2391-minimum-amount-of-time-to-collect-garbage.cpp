class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
//         int n = garbage.size();
        
//         unordered_map<char, int> lastHouseForGarbage;
        
//         unordered_map<char, int> totalGarbage;
        
//         for (int i = 0; i < n; i++) {
//             for (char ch : garbage[i]) {
//                 lastHouseForGarbage[ch] = i;
//                 totalGarbage[ch]++;
//             }
//         }
        
//         vector<int> timeToTravelTill(n);
        
//         for (int i = 1; i < n; i++) {
//             timeToTravelTill[i] = timeToTravelTill[i - 1] + travel[i - 1];
//         }
        
//         int time = 0;
        
//         for (auto& [garbageType, lastHouse] : lastHouseForGarbage) {
//             time += totalGarbage[garbageType] + timeToTravelTill[lastHouse];
//         }
//         return time;
        
        // WITHOUT EXTRA SPACE
        int n = garbage.size();
        
        vector<int> timeToTravelTill = travel;
        
        int M = 0, P = 0, G = 0; 
        
        int time = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < garbage[i].length(); j++) {
                if (garbage[i][j] == 'M') M = i;
                else if (garbage[i][j] == 'P') P = i;
                else G = i;
                time++;
            }
        }
        
        for (int i = 1; i < n - 1; i++) {
            timeToTravelTill[i] += timeToTravelTill[i - 1]; 
        }
        
        time += M == 0 ? 0 : timeToTravelTill[M - 1];
        time += P == 0 ? 0 : timeToTravelTill[P - 1];
        time += G == 0 ? 0 : timeToTravelTill[G - 1];
        
        return time;
    }
};