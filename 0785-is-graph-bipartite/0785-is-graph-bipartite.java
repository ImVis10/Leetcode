class Solution {
    public boolean isBipartite(int[][] graph) {
        // Intuition: Assign a flag to each node. Connected nodes must have different flags. 
        // Put the nodes with same flag in one set, so total two sets. Each set containing nodes of the same flag.
        // If it is possible to do the above, graph is bipartite, else it is not.
        int nVertices = graph.length;
        int[] flag = new int[nVertices];
        Arrays.fill(flag, -1);
        
        for (int i = 0; i < nVertices; i++) {
            if (flag[i] == -1) {
                if (!isBipartiteViaBFT(graph, i, flag)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private boolean isBipartiteViaBFT(int[][] graph, int v, int[] flag) {
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        flag[v] = 1;
        
        while(!q.isEmpty()) {
            int u = q.poll();
            for (int connNode : graph[u]) {
                if (flag[connNode] == -1) {
                    q.add(connNode);
                    flag[connNode] = 1 - flag[u];
                } else if (flag[u] == flag[connNode]) {
                    return false;
                }
            }
        }
        return true;
    }
}