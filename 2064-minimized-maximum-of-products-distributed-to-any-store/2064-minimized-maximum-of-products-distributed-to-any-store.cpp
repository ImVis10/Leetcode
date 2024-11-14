class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 0, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (feasible(n, mid, quantities)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
private:
    bool feasible(int numStores, int distributionQty, vector<int>& quantities) {
        int productId = 0, remQty = quantities[productId];
        for (int i = 0; i < numStores; i++) {
            if (remQty <= distributionQty) {
                productId++;
                if (productId == quantities.size()) return true;
                else remQty = quantities[productId];
            } else {
                remQty -= distributionQty;
            }
        }
        return false;
    }
};