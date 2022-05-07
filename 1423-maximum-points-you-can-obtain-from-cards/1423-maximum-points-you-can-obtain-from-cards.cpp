class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
  		int sum=0, max=0;

  		for(int i=0;i<k;i++){
  			sum+=cardPoints[i];
  		}   

  		int n=cardPoints.size();

  		int right=n-1;
  		max=sum;
  		for(int left=k-1;left>=0;right--, left--){
  			sum-=cardPoints[left];
  			sum+=cardPoints[right];

  			if(sum>max)
  				max=sum;
  		}      

  		return max;
    }
};