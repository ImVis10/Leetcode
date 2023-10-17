class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        // topological sort again
        int n = numCourses;
        
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        
        for (auto& course : prereq) {
            graph[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> res;
        
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            n--;
            res.push_back(currNode);
            for (auto& neigh : graph[currNode]) {
                if (--indegree[neigh] == 0) q.push(neigh);
            }
        }
        return n == 0 ? res : vector<int>();
    }
};