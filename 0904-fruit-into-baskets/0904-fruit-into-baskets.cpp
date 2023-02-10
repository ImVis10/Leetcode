class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // seems like a sliding window problem
        // so we have to find the widest sliding window consisting of two unique elements
        map<int, int> map;
        int baskets = 2; // window size
        int res = 0;
        int prev = 0;
        for (int i = 0;i < fruits.size(); i++) {
            map[fruits[i]] += 1;
            
            while(map.size() > baskets) {
                map[fruits[prev]] -= 1;
                if (map[fruits[prev]] == 0) {
                    map.erase(fruits[prev]);
                }
                prev++;
            }
            
            res = max(res, i - prev + 1);
        }
        
//         for(auto x : map) {
//             res += x.second;
//         }
        
//         int window_sum = res;
        
//         for (int i = baskets; i < fruits.size(); i++) {
//             // if the type of fruit already exists in the basket, add to the count of trees
//             // 
//             window_sum += map[i] - map[i - baskets];
//             res = max(res, window_sum);
//         }
        return res;
    }
};