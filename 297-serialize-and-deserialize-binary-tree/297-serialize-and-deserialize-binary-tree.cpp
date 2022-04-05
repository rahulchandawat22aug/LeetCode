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

    void treeToString(TreeNode* root, string &result){
        if(root==NULL){
            result+="N,";
            return;
        }
        result+=to_string(root->val);
        result+=",";
        treeToString(root->left, result);
        treeToString(root->right, result);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        if(root==NULL){
            return result;
        }
        treeToString(root, result);
        // cout<<result<<endl;
        return result;
    }

    TreeNode* stringToTree(string data, int &index, int n) {
        if(index>=n){
            return NULL;
        }
        if(data[index]=='N'){
            index+=2;
            return NULL;
        }
        bool sign=false;
        int x=0;
        while(data[index]!=','){
            if(data[index]=='-'){
                sign=true;
                index++;
            }
            x=x*10+(data[index]-'0');
            index++;
        }
        index++;
        x=sign?x*-1:x;

        TreeNode* root=new TreeNode(x);
        root->left=stringToTree(data, index, n);
        root->right=stringToTree(data, index, n);
        
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        if(n==0)
            return NULL;
        int index=0;
        return stringToTree(data, index, n);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));