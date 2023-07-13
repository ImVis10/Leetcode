class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> inward(numCourses);
        vector<int> outDegree(numCourses);
        
        for (auto& nodes : prerequisites) {
            cout << nodes.size();
            inward[nodes[1]].push_back(nodes[0]);
            outDegree[nodes[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (outDegree[i] == 0) q.push(i);
        }
        
        vector<bool> safe(numCourses);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for (auto from : inward[node])
                if (--outDegree[from] == 0) q.push(from);
        }
        
        for (auto b : safe) {
            if (!b) return b;
        }
        return true;
    }
};