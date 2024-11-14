class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // sort items in ascending order of price
        sort(items.begin(), items.end());

        // pre-compute maximum beauty until each index of item
        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        // binary search for each query
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            res[i] = binarySearch(items, queries[i]);
        }
        return res;
    }
private:
    int binarySearch(vector<vector<int>>& items, int target) {
        int left = 0, right = items.size() - 1;
        int maxBeauty = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] > target) right = mid - 1;
            else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        return maxBeauty;
    }
};