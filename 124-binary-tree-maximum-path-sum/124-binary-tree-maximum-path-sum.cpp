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
    int ans=INT_MIN;
    int getMaxPathSum(TreeNode* root) {

        if(root==NULL){
            return INT_MIN;
        }

        int leftSum=getMaxPathSum(root->left);
        int rightSum=getMaxPathSum(root->right);
        int currentValue=root->val;

        if(leftSum<0){
            leftSum=0;
        }
        if(rightSum<0){
            rightSum=0;
        }

        ans=max(ans, currentValue+leftSum+rightSum);

        return currentValue+max(leftSum, rightSum);

    }

    int maxPathSum(TreeNode* root) {
        getMaxPathSum(root);
        return ans;
    }
};