class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // can use BFS but should modify accordingly with a few conditions
        // while doing a BFS queue would have not just the node but also its price from the source, so that we can keep a check on the price for it to be as cheap as possible
        // Do BFS until the number of stops is at most k
        
        vector<vector<pair<int, int>>> adjList(n);
        for (auto flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]}); // from --> to, price
        }
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        int stops = 0;
        
        // minimum price of a node from source src
        vector<int> minPrice(n, 99999); // as the constraint for price is 10^4
        
        while (stops <= k) {
            int nodesInCurrLevel = q.size();
            
            while(nodesInCurrLevel > 0) {
                auto [node, priceAtCurrLevel] = q.front();
                q.pop();
                
                nodesInCurrLevel--;
                
                for (auto [neighbor, priceAtNextLevel] : adjList[node]) {
                    if (priceAtCurrLevel + priceAtNextLevel >= minPrice[neighbor]) {
                        continue;
                    }
                    minPrice[neighbor] = priceAtCurrLevel + priceAtNextLevel;
                    q.push({neighbor, minPrice[neighbor]});
                }   
            }
            stops++; // one round of BFS is complete, so increment stops by 1
        }
        return minPrice[dst] != 99999 ? minPrice[dst] : -1;
    }
};