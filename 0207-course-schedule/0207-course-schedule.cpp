class Solution {
public:
    bool dfs(int i,vector<vector<int>>& prerequisites,vector<int>& vis,vector<int>& pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto node:prerequisites[i]){
            if(!vis[node]){
                if(dfs(node,prerequisites,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[node]){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

         vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)){
                    return false;
                }
            }
        }
        return true;
    }      
};