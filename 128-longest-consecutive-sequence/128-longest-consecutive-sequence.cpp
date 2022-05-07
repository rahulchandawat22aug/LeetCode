class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        if(n==0 || n==1){
        	return n;
        }

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
        	mp[nums[i]]++;
        }

        for(auto current=mp.begin();current!=mp.end();current++){
        	int temp=current->first;
        	if(mp.count(temp-1)==0){

        		int count=1;
        		// auto temp1=current;
        		// current++;
        		while(mp.count(temp+1)){
        			// mp.erase(temp);
        			count++;
        			temp++;
        		}

        		if(count>result)
        			result=count;

        	}
        }



        return result;
    }
};