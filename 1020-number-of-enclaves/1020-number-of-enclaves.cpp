class Solution {
public:
   void dfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&vis){
      int n=grid.size();
      int m=grid[0].size();
      vis[i][j]=1;
      int dr[]={-1,0,1,0};
      int dc[]={0,1,0,-1};
      for(int x=0;x<4;x++){
        int nrow=i+dr[x];
        int ncol=j+dc[x];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
            dfs(nrow,ncol,grid,vis);
        }
      }
   }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,grid,vis);
            }
            
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1,j,grid,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
        
};