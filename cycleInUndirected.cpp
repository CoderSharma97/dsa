class Solution {
  public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,int parent){
        visited[node]=1;
        
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                bool ans = dfs(nbr,adj,visited,node);
                if(ans)return ans;
            }
            else if(visited[nbr] && parent !=nbr){
                return true;
            }
        }
        return false;
    }
    bool bfs(int node,vector<vector<int>>&adj,vector<int>&visited,int parent){
        queue<pair<int,int>>q;
        q.push({node,-1});
        visited[node]=1;
        
        while(!q.empty()){
            int node= q.front().first;
            int parent = q.front().second;
            q.pop();
            
            
            for(auto nbr : adj[node]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    q.push({nbr,node});
                }
                else if(visited[nbr] && parent !=nbr){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(v);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(v,0);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool ans = dfs(i,adj,visited,-1);
                if(ans)return ans;
            }
        }
        return 0;
    }
};
