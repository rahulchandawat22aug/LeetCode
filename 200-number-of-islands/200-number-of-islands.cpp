class Solution {
public:

    void markVi(vector<vector<char>>& grid, vector<vector<int>>& vi, int m, int n, int i, int j) {

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || vi[i][j]==1)
            return;

        vi[i][j]=1;
        markVi(grid, vi, m, n, i+1, j);
        markVi(grid, vi, m, n, i-1, j);
        markVi(grid, vi, m, n, i, j+1);
        markVi(grid, vi, m, n, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vi;

        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            vi.push_back(temp);
        }

        int count=0;
        for(int i=0;i<m;i++){
        
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vi[i][j]==0){
                    markVi(grid, vi, m, n, i, j);
                    count++;
                }
            }

        }

        return count;
    }

};