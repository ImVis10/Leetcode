class Solution(object):
    def closestMeetingNode(self, edges, node1, node2):
        """
        :type edges: List[int]
        :type node1: int
        :type node2: int
        :rtype: int
        """
        adj = collections.defaultdict(list)
        for i, dst in enumerate(edges):
            adj[i].append(dst)
            
        def bfs(src, distMap):
            q = deque()
            q.append([src, 0])
            distMap[src] = 0
            
            while q:
                node, dist = q.popleft()
                for neighbor in adj[node]:
                    if neighbor not in distMap:
                        q.append([neighbor, dist + 1])
                        distMap[neighbor] = dist + 1
                
            
        node1Dist = {}
        node2Dist = {}
        
        bfs(node1, node1Dist)
        bfs(node2, node2Dist)
        
        res = -1 # index of result node
        resDist = float("inf")
        
        for node in range(len(edges)):
            if node in node1Dist and node in node2Dist:
                dist = max(node1Dist[node], node2Dist[node])
                if dist < resDist:
                    res = node
                    resDist = dist
                    
        return res