// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>distance(v,1e8);
        distance[src]=0;
        
        for(int i=0;i<v-1;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt =  it[2];
                
                if(distance[u] != 1e8){
                    int newDistance = distance[u]+wt;
                    if( distance[v] > newDistance){
                        distance[v]=newDistance;
                    }
                }
            }
        }
        for(int i=0;i<v-1;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt =  it[2];
                
                if(distance[u] != 1e8){
                    int newDistance = distance[u]+wt;
                    if( distance[v] > newDistance){
                        return {-1};
                    }
                }
            }
        }
        
        return distance;
    }
};
