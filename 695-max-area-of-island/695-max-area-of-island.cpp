class Solution {
public:

	int getArea(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vi){


    	int m=grid.size();
    	int n=grid[0].size();
    	
    	if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==0 || vi[x][y]==1){
    		return 0;
    	}
    	vi[x][y]=1;
    	
    	int a=getArea(grid, x-1, y, vi);
    	int b=getArea(grid, x, y-1, vi);
    	int c=getArea(grid, x+1, y, vi);
    	int d=getArea(grid, x, y+1, vi);

    	return 1+a+b+c+d;
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	int m=grid.size();
    	int n=grid[0].size();

  		vector<vector<int>> vi(m, vector<int>(n, 0));

  		int maxArea=0;

  		for(int i=0;i<m;i++){
  			for(int j=0;j<n;j++){
				if(grid[i][j]==1 && vi[i][j]==0){
					int temp=getArea(grid, i, j, vi);
					if(temp>maxArea){
						maxArea=temp;
					}
				}
			}
  		}

  		return maxArea;      
    }
};