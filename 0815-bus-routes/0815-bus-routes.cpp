class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        int n = routes.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            for (auto& stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }
        
        vector<bool> visited(n);
        
        queue<int> q;
        q.push(source);
        
        int res = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                int stop = q.front();
                q.pop();
                if (stop == target) return res;
                for (int route : mp[stop]) {
                    if (visited[route]) continue;
                    visited[route] = true;
                    for (int nextStop : routes[route]) {
                        q.push(nextStop);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};