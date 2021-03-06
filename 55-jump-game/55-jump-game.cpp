class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int requiredJump=0, i=n-2;
        while(i>=0){
            requiredJump++;
            if(nums[i]>=requiredJump)
                requiredJump=0;
            i--;        
        }
        if(requiredJump==0)
            return true;

        return false;
    }
};