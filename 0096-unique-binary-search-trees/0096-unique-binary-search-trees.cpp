class Solution {
public:
    int numTrees(int n) {
        // consider each of [1.. n] can be a root
        // eg: [1, 2, 3]
        // rooted at 1
        /** 1      
             \ 
              2
               \
                3 
            
            1
             \
              3
              /
             2
        numTrees = 1 tree (empty tree) with no nodes on left subtree and 2 trees with 2 nodes on right subtree
                 = numTrees[0] * numTrees[2];
             */
        // rooted at 2
        /**  2
            / \
            1  3
        numTrees = 1 tree  with 1 node on left subtree and 1 tree1 with node1 on right subtree
                 = numTrees[1] * numTrees[1];
        */
        
        // rooted at 3
        /** 3
           /
          2
         /
        1
        
        3
       /
      1
       \
        2
    numTrees = 2 trees with 2 nodes on left subtree and 1 tree (empty tree)  with no nodes on right subtree
                 = numTrees[2] * numTrees[0];
        */
        
        vector<int> trees(n + 1, 1);
        for (int node = 2; node <= n; node++) { // as trees with no nodes, 1 node have only one possible unique BST
            int total = 0;
            for (int root = 1; root <= node; root++) {
                int leftTree = root - 1;
                int rightTree = node - root;
                total += trees[leftTree] * trees[rightTree];
            }
            trees[node] = total;
        }
        return trees[n];
    }
};