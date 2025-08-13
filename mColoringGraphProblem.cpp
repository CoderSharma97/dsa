class Solution {
  public:
    bool isPossible(vector<vector<int>>&adj,int v,vector<int>&color,int c ){
        
        for(auto nbr : adj[v]){
            if(color[nbr]==c && color[nbr] != -1)return 0;
        }
        return 1;
    }
    bool solve(int v,vector<vector<int>>&adj,int m,vector<int>&color){
        if(v==-1){
            return 1;
        }
        
        for(int i=1;i<=m;i++){
            if(isPossible(adj,v,color,i)){
                color[v]=i;
                bool ans = solve(v-1,adj,m,color);
                if(ans)return ans;
                color[v]=-1;
            }
        }
        return 0;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        vector<int>color(v,-1);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return solve(v-1,adj,m,color);
        
    }
};
