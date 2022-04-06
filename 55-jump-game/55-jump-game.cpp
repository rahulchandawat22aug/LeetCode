class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        if(nums[0]==0)
            return false;

        int requiredJump=0, i=n-2;
        while(i>=0){
            requiredJump++;
            if(nums[i]>=requiredJump)
                requiredJump=0;
            i--;        
        }
        if(nums[0]>=requiredJump){
            return true;
        }
        return false;
    }
};