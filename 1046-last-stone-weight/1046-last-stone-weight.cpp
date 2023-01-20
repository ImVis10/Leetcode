class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int heaviestStone = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int secondHeaviestStone = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if (heaviestStone == secondHeaviestStone) {
                continue;
            } else {
                // push the difference to heap
                stones.push_back(heaviestStone - secondHeaviestStone);
                push_heap(stones.begin(), stones.end());
            }
        }
        return stones.size() == 0 ? 0 : stones.front();
    }
};