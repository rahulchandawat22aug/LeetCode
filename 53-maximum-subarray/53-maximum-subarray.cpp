class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }      

        int max, sum;
        max=INT_MIN;
        sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum < nums[i]){
                sum=nums[i];
            }
            if(sum > max)
                max=sum;
        }
        return max;
    }
};