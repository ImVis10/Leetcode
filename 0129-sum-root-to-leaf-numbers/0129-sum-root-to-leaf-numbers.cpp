class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;  // To store the total sum of all root-to-leaf numbers
        int currentNumber = 0;  // To store the number for the current path
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                // No left child, process current node and go right
                currentNumber = currentNumber * 10 + cur->val;  // Add current node's value to path
                if (cur->right == NULL) {
                    totalSum += currentNumber;  // Leaf node, add the current path number to totalSum
                }
                cur = cur->right;
            } else {
                // Find the inorder predecessor of current node
                TreeNode* pred = cur->left;
                int steps = 1;
                while (pred->right != NULL && pred->right != cur) {
                    pred = pred->right;
                    steps++;
                }

                if (pred->right == NULL) {
                    // Establish a temporary link from the predecessor to the current node
                    pred->right = cur;
                    currentNumber = currentNumber * 10 + cur->val;  // Add current node's value to path
                    cur = cur->left;
                } else {
                    // If the temporary link is already established, break it
                    pred->right = NULL;

                    // If it's a leaf node, add the current path number to totalSum
                    if (pred->left == NULL && pred->right == NULL) {
                        totalSum += currentNumber;
                    }

                    // Remove the last `steps` digits from the current number (backtrack)
                    currentNumber /= pow(10, steps);
                    cur = cur->right;
                }
            }
        }

        return totalSum;
    }
};
