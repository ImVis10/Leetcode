class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // at every position check on its left and right
        // if both are empty, a flower can be planted
        // if not, a flower can't be planted
        
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};