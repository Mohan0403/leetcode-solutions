class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited=grid;
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==2){
                    q.push({i,j});
                }
                else if(visited[i][j]==1){
                    fresh++;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        if(fresh==0) return 0;
        if(q.empty()) return -1;
        int minutes=-1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [row,col]= q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==1){
                        visited[nrow][ncol]=2;
                        fresh--;
                        q.push({nrow,ncol});
                    }
                }        
                    }
                minutes++;
        }
        if(fresh==0) {
            return minutes;
        } 
        return -1;
        
    }
};