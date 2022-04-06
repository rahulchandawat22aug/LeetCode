class Solution {
public:

    // bool makeJump(vector<int>& nums, int curr, int n){
    //     if(curr>=(n-1))
    //         return true;
    //     if(nums[curr]<=0)
    //         return false;

    //     int x=nums[curr];

    //     while(x>=1){
    //        bool result=makeJump(nums, curr+x,n); 
    //        if(result==true)
    //         return true;
    //         x--;
    //     }

    //     return false;

    // }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        if(nums[0]==0)
            return false;

        int requiredJump=1, i=n-2;
        while(i>=0){
            if(nums[i]>=requiredJump)
                requiredJump=1;
            else
                requiredJump++;
            i--;        
        }
        if(nums[0]>=requiredJump){
            return true;
        }
        return false;
    }
};