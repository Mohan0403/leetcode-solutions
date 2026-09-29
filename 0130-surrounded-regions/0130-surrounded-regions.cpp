class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> & vis){
        int n=board.size();
        int m=board[0].size();
        vis[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int x=0;x<4;x++){
            int nrow=i+dr[x];
            int ncol=j+dc[x];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j]=='O' && vis[n-1][j]==0){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

        
    }
};