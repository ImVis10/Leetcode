class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> curr = {0, 0};
        
        set<pair<int, int>> set; 
        set.insert(curr);
        
        for (char dir : path) {
            if (dir == 'N') {
                curr.second += 1;
            } else if (dir == 'E') {
                curr.first += 1;
            } else if (dir == 'W') {
                curr.first -= 1;
            } else {
                curr.second -= 1;
            }
            
            if (set.find(curr) != set.end()) return true;
            
            set.insert(curr);
        }
        return false;
    }
};