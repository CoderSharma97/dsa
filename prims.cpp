class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum = 0;
        vector<int>visited(v,0);
        
        
        
        
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if(visited[node])continue;
            sum+=dist;
            visited[node]=1;
            
            for(auto it : adj[node]){
                
                int dist = it[1];
                int nbr = it[0];
                if(!visited[nbr])
                pq.push({dist,nbr});
            }
        }
        
        return sum;
    }
};
