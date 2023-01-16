class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // at every position check on its left and right
        // if both are empty, a flower can be planted
        // if not, a flower can't be planted
        
//         flowerbed.insert(flowerbed.begin(), 0);
//         flowerbed.push_back(0);
        
//         for (int i = 1; i < flowerbed.size() - 1; i++) {
//             if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
//                 flowerbed[i] = 1;
//                 n--;
//             }
//         }
//         return n <= 0;
        
        int empty = flowerbed[0] ? 0 : 1;
        //  we can place at most (c - 1) / 2 flowers into the gap, where c is a number of continuous 0 in the gap. With two exceptions, when first or last position is 0 we need extra +1.
        for (int flower : flowerbed) {
            if (flower) {
                n -= ((empty - 1) / 2);
                empty = 0;
            } else {
                empty++;
            }
        }
        n -= (empty / 2);
        return n <= 0;
    }
};