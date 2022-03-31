/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<TreeNode*> nodes;
void inOrder(TreeNode* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    nodes.push_back(root);
    inOrder(root->right);

    return;
}

TreeNode* buildBST(int start, int end){
    if(start > end){
        return NULL;
    }
    
    int mid=(start+end)/2;
    TreeNode* root=nodes[mid];

    root->left=buildBST( start, mid-1);
    root->right=buildBST( mid+1, end);

    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    if(root==NULL)
        return root;

    // vector<TreeNode*> nodes;
    inOrder(root);

    int n=nodes.size();
    TreeNode* newHead;
    newHead=buildBST( 0, n-1);
    return newHead;
}
};