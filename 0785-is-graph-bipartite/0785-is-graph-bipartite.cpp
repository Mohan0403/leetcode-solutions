class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int c[n];
        for(int i=0;i<graph.size();i++){
            c[i]=-1;
        }
        for(int i = 0; i < n; i++) {

            if(c[i] == -1) {

                queue<int> q;
                q.push(i);
                c[i] = 0;

                while(!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for(int adj : graph[node]) {

                        if(c[adj] == -1) {
                            c[adj] = 1 - c[node];
                            q.push(adj);
                        }
                        else if(c[adj] == c[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};