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
                
                if (node) {
                    res += to_string(node->val) + ',';
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    res += "#,";
                }
            }     
        }
        res.pop_back();
        cout <<  res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "#") return NULL;
        
        stringstream ss(data);
        string item;
        
        getline(ss, item, ','); // get a char separated by delimiter ','
        TreeNode* root = new TreeNode(stoi(item));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
            }
            
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    node->right = new TreeNode(stoi(item));
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }

private:
    vector<char> splitString(string s) {
        vector<char> res;
        stringstream ss(s);
        
        string item;
        
        while (getline(ss, item, ',')) {
            if (item.size() == 1) {
                res.push_back(item[0]);                
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));