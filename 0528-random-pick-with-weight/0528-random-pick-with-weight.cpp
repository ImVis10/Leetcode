class Solution {
    vector<int> weights;
public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (int weight : w) {
            sum += weight;
            weights.push_back(sum);
        }
    }
    
     /**say we have arr = [1,2,3,4], '1' must have prob of 1 / 1+2+3+4 , '2' has prob of 2 / 10 and ....
     so first get the prefixsum of values to get their weights
     get a random number between [0, 9)
     if the number is 0, return index 0
     if the number is [1, 3) return index 1
     if the number is [3, 6) return index 2
     if the number is [6, 10) return index 3
     **/
    int pickIndex() {
        int target = rand() % weights[weights.size() - 1]; //randomly picking a number in range [0, cumulative sum]
        auto it = upper_bound(weights.begin(), weights.end(), target);
        return it - weights.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */