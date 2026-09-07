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

    void serializeTree(TreeNode* root, string& s) {

        if(root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeTree(root->left, s);
        serializeTree(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;

        serializeTree(root, s);

        return s;
    }

    TreeNode* deserializeTree(vector<string>& data, int& index) {

        if(data[index] == "#") {
            index++;
            return NULL;
        }

        TreeNode* root =
            new TreeNode(stoi(data[index]));

        index++;

        root->left = deserializeTree(data, index);
        root->right = deserializeTree(data, index);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> tokens;
        string token;

        stringstream ss(data);

        while(getline(ss, token, ','))
            tokens.push_back(token);

        int index = 0;

        return deserializeTree(tokens, index);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));