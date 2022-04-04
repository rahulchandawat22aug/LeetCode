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

        if(currentValue>=0){
            if(leftSum<0){
                if(rightSum<0){
                    if(ans<currentValue){
                        ans=currentValue;
                    }
                    return currentValue;
                }
                else{
                    if(ans<(currentValue+rightSum)){
                        ans=currentValue+rightSum;
                    }
                    return(currentValue+rightSum);
                }
            }
            else{
                if(rightSum<0){
                    if(ans<(currentValue+leftSum)){
                        ans=currentValue+leftSum;
                    }
                    return currentValue+leftSum;
                }
                else{
                    if(ans<(currentValue+rightSum+leftSum)){
                        ans=currentValue+rightSum+leftSum;
                    }
                    return (currentValue+leftSum)>(currentValue+rightSum)?(currentValue+leftSum):(currentValue+rightSum);
                }
            }
        }

        if(leftSum<0){
                if(rightSum<0){
                    if(ans<currentValue){
                        ans=currentValue;
                    }
                    return currentValue;
                }
                else{
                    if(ans<(rightSum+currentValue)){
                        ans=rightSum+currentValue;
                    }
                    return(currentValue+rightSum);
                }
        }   
        else{
            if(rightSum<0){
                if(ans<(currentValue+leftSum)){
                    ans=currentValue+leftSum;
                }
                return currentValue+leftSum;
            }
            else{
                
                int x=max((currentValue+leftSum+rightSum),max((currentValue+leftSum), (currentValue+rightSum)));
                ans=max(ans, x);


                int temp=(currentValue+leftSum)>(currentValue+rightSum)?(currentValue+leftSum):(currentValue+rightSum);
                return temp;
            }
        }
    }

    int maxPathSum(TreeNode* root) {
        getMaxPathSum(root);
        return ans;
    }
};