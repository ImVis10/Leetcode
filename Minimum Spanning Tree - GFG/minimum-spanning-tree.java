//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass
{
    public static void main(String args[]) throws IOException {

        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int V = Integer.parseInt(str[0]);
            int E = Integer.parseInt(str[1]);
    
            ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<ArrayList<ArrayList<Integer>>>();
            for(int i=0;i<V;i++)
            {
                adj.add(new ArrayList<ArrayList<Integer>>());
            }
            
            int i=0;
            while (i++<E) {
                String S[] = read.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                int w = Integer.parseInt(S[2]);
                ArrayList<Integer> t1 = new ArrayList<Integer>();
                ArrayList<Integer> t2 = new ArrayList<Integer>();
                t1.add(v);
                t1.add(w);
                t2.add(u);
                t2.add(w);
                adj.get(u).add(t1);
                adj.get(v).add(t2);
            }
            
            Solution ob = new Solution();
            
            System.out.println(ob.spanningTree(V, adj));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Pair {
  int node;
  int weight;
  public Pair(int node, int weight) {
    this.node = node;
    this.weight = weight;
  }
}

public class Solution
{
  public static int spanningTree(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj) {
      PriorityQueue <Pair> pq = new PriorityQueue<>((x, y) -> x.weight - y.weight); // priority queue for min heap
      int[] visited = new int[V + 1]; // V + 1 as vertices here start from 1 not 0
      pq.add(new Pair(1, 0)); // as our nodes start from 1 not 0
      int weightOfMST = 0;
      while (!pq.isEmpty()) {
		int weight = pq.peek().weight; // always the least weighted edge on the top, we can get that in O(1) as it is a min heap
        int node = pq.peek().node; 
        //System.out.println(node);
        pq.remove(); // pop the node out from the priority queue

        if (visited[node] == 1) { // if the node is already visited (already a part of MST)
          continue; // go to the next node
        }
		
		// if not visited yet (not a part of MST), proceed
        visited[node] = 1; // mark the node as visited (add it to MST)
        weightOfMST += weight; // add the node's weight to the weight of MST
        for (int i = 0; i < adj.get(node).size(); i++) { // get all the adjacent nodes
			int adjNode = adj.get(node).get(i).get(0); // get the node
			int weightOfAdjNode = adj.get(node).get(i).get(1); // get the weight
			if (visited[adjNode] == 0) { // if the adjacent node is not visited(not a part of the MST)
				pq.add(new Pair(adjNode, weightOfAdjNode)); // add the adjacent node to priority queue
			}
		}
      }
      return weightOfMST;
}
}
