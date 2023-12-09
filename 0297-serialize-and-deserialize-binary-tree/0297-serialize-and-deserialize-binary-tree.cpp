/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) res += "#,";
                else {
                    res += to_string(node->val) + ',';
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        res.pop_back(); // remove the extra ','
        cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "#") return NULL;
        stringstream ss(data);
        string node;
        
        getline(ss, node, ','); // get each node with , being the delimiter
        
        TreeNode* root = new TreeNode(stoi(node));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            
            getline(ss, node, ',');
            if (node != "#") {
                currNode->left = new TreeNode(stoi(node));
                q.push(currNode->left);
            }
            
            getline(ss, node, ',');
            if (node != "#") {
                currNode->right = new TreeNode(stoi(node));
                q.push(currNode->right);
            }
            
            
        }
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));