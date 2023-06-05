class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        int deltaY = getDeltaY(coordinates[0], coordinates[1]);
        int deltaX = getDeltaX(coordinates[0], coordinates[1]);
        
        // check relative to a point.. let's take point '0'
        for (int i = 2; i < n; i++) {
            if (deltaY * getDeltaX(coordinates[0], coordinates[i]) != (deltaX * getDeltaY(coordinates[0], coordinates[i]))) {
                return false;
            }
        }
        return true;
    }
    
private:
    int getDeltaY(vector<int> p1, vector<int> p2) {
        return p2[1] - p1[1];
    }
    
    int getDeltaX(vector<int> p1, vector<int> p2) {
        return p2[0] - p1[0];
    }
};